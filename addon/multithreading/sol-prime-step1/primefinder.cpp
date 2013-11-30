#include "primefinder.h"
#include <QApplication>
#include "isprime.h"

PrimeFinder::PrimeFinder()
{
    m_Busy = false;
}

void PrimeFinder::cancel() {
    m_Busy = false;
}

bool PrimeFinder::isBusy() const {
    return m_Busy;
}
void PrimeFinder::findPrimesUpTo(qlonglong v) {
    m_Busy = true;
    m_foundPrimes << 2;
    qlonglong maxValue =v;
    int percent = 0;
    for (qlonglong i=3; i<maxValue; i += 2) {
        if (isPrime(i)) m_foundPrimes << i;
        int newPercent = 100 * (double) i / maxValue;
        if (newPercent > percent) {
            emit progressValueChanged(newPercent);
            percent = newPercent;
            qApp->processEvents();
        }
        if (!m_Busy) break;
    }
    m_Busy = false;
}
