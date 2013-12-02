#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QObject>
#include <QList>

class PrimeFinder: public QObject
{
    Q_OBJECT
public:
    PrimeFinder();

public slots:
    void clear() {m_foundPrimes.clear();}
    void findPrimesUpTo(qlonglong v);
    void cancel();
    bool isBusy() const;
    QList<qlonglong> foundPrimes() const {return m_foundPrimes;}
signals:
    void progressValueChanged(int);
private:
    bool m_Busy;
    QList<qlonglong> m_foundPrimes;
};

#endif // PRIMEFINDER_H
