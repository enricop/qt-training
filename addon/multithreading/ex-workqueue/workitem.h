#ifndef WORKITEM_H
#define WORKITEM_H

// represents one item of work for consumer threads

class WorkItem
{
public:
    WorkItem();
    int getValue();
    int timeout();

private:
    int timeoutval; // time consumer will wait between processing each item
    int power;
    int value;
};

#endif
