#ifndef WORKQUEUE_H
#define WORKQUEUE_H

#include <QList>
#include <QTextEdit>
#include <QThread>

class WorkProducer;
class WorkConsumer;

// WorkWueue //////////////////////////////////////////////////////////////////

class WorkQueue : public QTextEdit
{
public:
    WorkQueue(int, QWidget *parent=0);
    ~WorkQueue();

private:
    WorkProducer *producer;
    QList<WorkConsumer*> consumerlist;
};

// WorkProducer ///////////////////////////////////////////////////////////////

class WorkProducer : public QThread 
{
    Q_OBJECT

public:
    WorkProducer(int items=0);

protected:
    virtual void run();

private:
    int numitems;
};

// WorkConsumer ///////////////////////////////////////////////////////////////

class WorkConsumer : public QThread
{
    Q_OBJECT

public:
    WorkConsumer(int id);

protected:
	virtual void run();

signals:
	void newValue(QString);

private:
	int threadid;
};

#endif
