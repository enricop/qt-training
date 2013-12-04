#include "primefinder.h"
#include <QApplication>
#include "isprime.h"
#include <QThreadPool>
PrimeChecker::PrimeChecker(qlonglong valueToCheck, QObject* parent)
    : QObject(parent) {
    setAutoDelete(true);
    m_values << valueToCheck;
}

PrimeChecker::PrimeChecker(QList<qlonglong> values, QObject* parent)
    : QObject(parent) {
    setAutoDelete(true);
    m_values = values;
}


void PrimeChecker::run() {
    foreach (qlonglong v, m_values)        
        if (isPrime(v)) emit primeFound(v);
}

PrimeFinder::PrimeFinder()
{
    m_Busy = false;
    m_threadCount = 1;
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
        values << i;
        if (values.size() > m_granularity) {
           PrimeChecker *pc = new PrimeChecker(values);
           connect (pc, SIGNAL(primeFound(qlonglong)), this, SLOT(foundPrime(qlonglong)));
           QThreadPool::globalInstance()->start(pc);
           qApp->processEvents();
           values.clear();
        }
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
