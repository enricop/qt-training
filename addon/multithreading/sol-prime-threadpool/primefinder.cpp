#include "primefinder.h"
#include "isprime.h"
#include <QApplication>
#include <QThreadPool>
#include <QThread>

// PrimeFinder methods

PrimeFinder::PrimeFinder() {
    m_Busy = false;
    setNumThreads(1);
    m_granularity = 1;
}

void PrimeFinder::setNumThreads(int nThreads) {
    QThreadPool::globalInstance()->setMaxThreadCount(nThreads);
}

void PrimeFinder::setGranularity(int numValues) {
    m_granularity = numValues;
}

void PrimeFinder::cancel() {
    m_Busy = false;    
    foreach (PrimeChecker* checker, findChildren<PrimeChecker*>()) {
       if (checker) checker->cancel();
    }

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
    QList<qlonglong> values;
    for (qlonglong i=3; i<maxValue; i += 2) {
        if (!m_Busy) break;
        values << i;
        if ((i == maxValue - 2) || (values.size() > m_granularity)) {
           PrimeChecker *pc = new PrimeChecker(values, this);
           connect (pc, SIGNAL(primeFound(qlonglong)), this, SLOT(foundPrime(qlonglong)));
           QThreadPool::globalInstance()->start(pc);
           values.clear();
           qApp->processEvents();
        }        
    }
    while (!QThreadPool::globalInstance()->waitForDone(200))
        qApp->processEvents();
    if (m_Busy) emit progressValueChanged(100);
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

// -------------------------------------------------------------------------------
// PrimeChecker methods

PrimeChecker::PrimeChecker(QList<qlonglong> values, QObject* parent)
: QObject(parent) {
    setAutoDelete(true);
    isCancelled=false;
    m_values = values;
}

void PrimeChecker::run() {
    foreach (qlonglong v, m_values) {
        if (isCancelled) return;
        if (isPrime(v)) emit primeFound(v);
    }
}

void PrimeChecker::cancel() {
    disconnect();
    isCancelled=true;
    m_values.clear();
}
