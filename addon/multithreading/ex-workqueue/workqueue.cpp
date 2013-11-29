#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QtDebug>
#include <QQueue>
#include <QTime>

#include "time.h"
#include "workqueue.h"
#include "workitem.h"

// shared data

QMutex workmutex;
QWaitCondition workcondition;
QQueue<WorkItem> workqueue;
bool workisdone = false;
int worknumwaiting = 0;

// WorkQueue //////////////////////////////////////////////////////////////////

WorkQueue::WorkQueue(int max, QWidget *parent) 
: QTextEdit(parent) {
    setReadOnly(true);

    // start the producer thread
    producer = new WorkProducer(25);
    producer->start();

    // start the consumer threads and connect them to GUI thread
    for (int n = 1; n <= max; n++) {
        WorkConsumer *consumer = new WorkConsumer(n);
        consumerlist << consumer;
        connect(consumer, SIGNAL(newValue(QString)), 
                this,     SLOT(append(QString)),
                Qt::QueuedConnection);
        consumer->start();
    }
}

WorkQueue::~WorkQueue() {
    // tell all the consumer threads to exit
    workmutex.lock();
    workisdone = true;
    workcondition.wakeAll();
    workmutex.unlock();

    // wait for each thread to complete
    producer->wait();
    producer->deleteLater();
    foreach (WorkConsumer *consumer, consumerlist) {
        consumer->wait();
        consumer->deleteLater();
    }
}

// WorkProducer ///////////////////////////////////////////////////////////////

WorkProducer::WorkProducer(int items) {
    numitems = items;
}

void WorkProducer::run() {
    qsrand(QTime::currentTime().msec());
    for (int n = 0; n < numitems; n++) {
        QMutexLocker locker(&workmutex);
        WorkItem item;
        workqueue.enqueue(item);
        if (worknumwaiting > 0) {
            workcondition.wakeOne();
            worknumwaiting--;
        }
    }
}

// WorkConsumer ///////////////////////////////////////////////////////////////

WorkConsumer::WorkConsumer(int id)
{
    threadid = id;
}

void WorkConsumer::run()
{
    QMutexLocker locker(&workmutex);

    while (! workisdone) {
	if (workqueue.isEmpty()) {
            worknumwaiting++;
            workcondition.wait(locker.mutex());
        } else {
            WorkItem item = workqueue.dequeue();
            locker.unlock();

            // send an inter thread signal to the GUI thread
            emit newValue(QString("Thread %1 Value is %2")
                          .arg(threadid)
                          .arg(item.getValue()));
            msleep(item.timeout());
            locker.relock();
        }
    }

    return;
}
