#include <QtGlobal>
#include "time.h"
#include "workitem.h"

WorkItem::WorkItem()
{
    power = qrand() % 20;
    value = qrand() % 7;
    timeoutval = qrand() % 1000; 
}

int WorkItem::getValue()
{
    // useless busy work
    int retval = 1;
    for (int i = 1; i <= power; i++) retval *= value;
    return retval;
}

int WorkItem::timeout()
{
    return timeoutval;
}
