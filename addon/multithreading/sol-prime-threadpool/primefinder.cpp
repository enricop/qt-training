#include "primefinder.h"
#include <QApplication>
#include "isprime.h"
#include <QThreadPool>
PrimeChecker::PrimeChecker(qlonglong valueToCheck, QObject* parent)
    : QObject(parent), m_value(valueToCheck) {
    setAutoDelete(true);
}

void PrimeChecker::run() {
    if (isPrime(m_value))
        emit primeFound(m_value);
}

PrimeFinder::PrimeFinder()
{
    m_Busy = false;
    m_threadCount = 1;
}

void PrimeFinder::setNumThreads(int nThreads) {
    QThreadPool::globalInstance()->setMaxThreadCount(nThreads);
}

void PrimeFinder::cancel() {
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
