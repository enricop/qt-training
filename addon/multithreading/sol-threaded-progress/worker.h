#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(QObject *parent = 0);
    
public slots:
    void start();
    void finish();

signals:
    void update(int percent);
    void finished();

private:
    volatile bool mAbort;
};

#endif // WORKER_H
