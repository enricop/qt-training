#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QList>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>

class PrimeChecker : public QThread {
    Q_OBJECT
public:
    explicit PrimeChecker(QObject* parent =0);
    void run();
public slots:
    /** @param v if -1, then there are no more numbers to check */
    void checkValue(qlonglong v);
    void cancel();
    void stopWhenDone();
signals:
    void primeFound(qlonglong v);
private:
    bool m_aborted;
    bool m_noMoreWork;
    QList<qlonglong> m_queue;
    QMutex m_mutex;
    QWaitCondition m_waitCondition;
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
    QList<PrimeChecker*> m_checkers;
    qlonglong maxValue;
    int percent;
};

#endif // PRIMEFINDER_H
