#include "primefinder.h"
#include <QApplication>
#include "isprime.h"
#include <QThreadPool>

PrimeChecker::PrimeChecker(QObject* parent) : QThread(parent) {
    m_aborted = false;
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
       if (m_queue.isEmpty()) {
           QMutexLocker locker(&m_mutex);
           m_waitCondition.wait(&mutex, 1000);
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
    foreach (PrimeChecker* pc, m_checkers) {
        pc->cancel();
        pc->deleteLater();

    }
    m_checkers->clear();
    for (int i=0; i<nThreads; ++i) {
        PrimeChecker* c = new PrimeChecker();
        m_checkers << c;
        c->start();
    }
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
    m_foundPrimes << 2;
    maxValue =v;
    percent = 0;

    for (qlonglong i=3; i<maxValue; i += 2) {
        PrimeChecker *pc = new PrimeChecker(i);
        connect (pc, SIGNAL(primeFound(qlonglong)), this, SLOT(foundPrime(qlonglong)));
        QThreadPool::globalInstance()->start(pc);
        qApp->processEvents();
        if (!m_Busy) break;
    }
    QThreadPool::globalInstance()->waitForDone();
    qApp->processEvents();
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
