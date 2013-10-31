#include <QThread>
#include "worker.h"

extern void busy_work();

Worker::Worker(QObject *parent) :
    QObject(parent), mAbort(false)
{
}

void Worker::start()
{
    // do one thousand iterations
    for (int n = 0; n < 1000; n++) {
        if (mAbort) break;

        // do some work
        busy_work();

        // let world know our progress
        if ((n % 10) == 0) emit update(n / 10);
    }

    // emit final update
    emit update(100);

    // we are done
    emit finished();
}

void Worker::finish()
{
    // gracefully shutdown
    mAbort = true;
    if (thread() != QThread::currentThread()) {
        thread()->quit();
        thread()->wait();
    }
}
