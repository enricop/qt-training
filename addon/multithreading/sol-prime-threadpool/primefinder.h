#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QObject>
#include <QList>
#include <QRunnable>

class PrimeChecker : public QObject, public QRunnable {
    Q_OBJECT
public:
    explicit PrimeChecker(qlonglong valueToCheck, QObject* parent =0);
    void run();
signals:
    void primeFound(qlonglong v);
private:
    qlonglong m_value;
};


class PrimeFinder: public QObject
{
    Q_OBJECT
public:
    PrimeFinder();

public slots:
    void setNumThreads(int nThreads);
    void findPrimesUpTo(qlonglong v);
    void cancel();
    bool isBusy() const;
    QList<qlonglong> foundPrimes() const {return m_foundPrimes;}
    void foundPrime(qlonglong pv);
signals:
    void progressValueChanged(int);
private:
    bool m_Busy;
    int m_threadCount;
    QList<qlonglong> m_foundPrimes;
    qlonglong maxValue;
    int percent;
};

#endif // PRIMEFINDER_H