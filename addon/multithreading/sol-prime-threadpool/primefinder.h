#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QObject>
#include <QList>
#include <QRunnable>
#include <QMutex>

/** A QRunnable that checks a batch of numbers for prime-hood. */
class PrimeChecker : public QObject, public QRunnable {
    Q_OBJECT
public:
    explicit PrimeChecker(QList<qlonglong> valuesToCheck, QObject* parent=0);
    void run();
    void cancel();
signals:
    void primeFound(qlonglong v);
    void finished();
private:
    volatile bool isCancelled;
    QList<qlonglong> m_values;

};


class PrimeFinder: public QObject
{
    Q_OBJECT
public:
    PrimeFinder();

public slots:
    void setGranularity(int numValues);
    void setNumThreads(int nThreads);
    void findPrimesUpTo(qlonglong v);
    void cancel();
    bool isBusy() const;
    QList<qlonglong> foundPrimes() const {return m_foundPrimes;}
    void foundPrime(qlonglong pv);
signals:
    void progressValueChanged(int);
private:
    int m_granularity;
    volatile bool m_Busy;

    QList<qlonglong> m_foundPrimes;
    qlonglong maxValue;
    int percent;
};

#endif // PRIMEFINDER_H
