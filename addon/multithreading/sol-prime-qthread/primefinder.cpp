#include "primefinder.h"
#include <QApplication>
#include "isprime.h"
#include <QThreadPool>

PrimeChecker::PrimeChecker(QObject* parent) : QThread(parent) {
    m_aborted = false;
    m_noMoreWork = false;
}

void PrimeChecker::stopWhenDone() {
    m_noMoreWork = true;
}

void PrimeChecker::run() {
    while (!m_aborted) {

       while (!m_queue.isEmpty()) {
           m_mutex.lock();
           qlonglong v = m_queue.front();
           m_queue.pop_front();
           m_mutex.unlock();
           if (isPrime(v)) emit primeFound(v);
       }
       if (m_noMoreWork) return;
       if (m_queue.isEmpty()) {
           QMutexLocker locker(&m_mutex);
           m_waitCondition.wait(&m_mutex, 1000);
       }
    }
}

void PrimeChecker::cancel() {
   m_aborted = true;
   m_queue.clear();
}

void PrimeChecker::checkValue(qlonglong v) {
    QMutexLocker locker(&m_mutex);
    m_queue << v;
    m_waitCondition.wakeOne();
}


PrimeFinder::PrimeFinder()
{
    m_Busy = false;
    m_threadCount = 1;
}

void PrimeFinder::setNumThreads(int nThreads) {
    m_threadCount = nThreads;
}

void PrimeFinder::cancel() {
    foreach (PrimeChecker* pc, m_checkers)
        pc->cancel();
    m_Busy = false;
}

bool PrimeFinder::isBusy() const {
    return m_Busy;
}

void PrimeFinder::findPrimesUpTo(qlonglong v) {
    m_Busy = true;
    m_foundPrimes.clear();
    qDeleteAll(m_checkers);
    m_checkers.clear();
    m_foundPrimes << 2;
    maxValue =v;
    percent = 0;

    for (int t=0; t<m_threadCount; ++t) {
        PrimeChecker *pc = new PrimeChecker();
        connect (pc, SIGNAL(primeFound(qlonglong)), this, SLOT(foundPrime(qlonglong)));
        m_checkers << pc;
        pc->start();
    }

    int idx = 0;
    for (qlonglong i=3; i<maxValue; i += 2) {
        m_checkers.at(idx)->checkValue(i);
        idx = ++idx % m_threadCount;
        if (idx == 0) qApp->processEvents();
        if (!m_Busy) break;
    }
    foreach (PrimeChecker* pc, m_checkers)
        pc->stopWhenDone();
    qApp->processEvents();
    foreach (PrimeChecker* pc, m_checkers) {
        qApp->processEvents();
        pc->wait();
    }
    m_Busy = false;
}

void PrimeFinder::foundPrime(qlonglong pv) {
    m_foundPrimes << pv;
    int newPercent = 100 * (double) pv / maxValue;

    if (newPercent > percent) {
        emit progressValueChanged(newPercent);
        percent = newPercent;
        qApp->processEvents();
    }
}
