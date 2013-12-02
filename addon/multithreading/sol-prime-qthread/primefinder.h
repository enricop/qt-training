#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QList>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>


// Worker thread created by PrimeFinder.
class PrimeChecker : public QThread {
    Q_OBJECT
public:
    explicit PrimeChecker(QObject* parent =0);
    void run();
public slots:
    void checkValue(qlonglong v);
    void cancel();
    void stopWhenDone();
signals:
    void primeFound(qlonglong v);
private:
    bool m_aborted;
    bool m_stopWhenDone;
    QList<qlonglong> m_queue;
    QMutex m_mutex;
    QWaitCondition m_waitCondition;
};

// Runs in the main thread
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
    QList<PrimeChecker*> m_checkers;
    qlonglong maxValue;
    int percent;
};

#endif // PRIMEFINDER_H
