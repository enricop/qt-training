#ifndef MYRECEIVER_H
#define MYRECEIVER_H

#include <QObject>

class MyReceiver : public QObject
{
    Q_OBJECT

public:
    MyReceiver(QObject *parent = 0);

public slots:
    void aSlot();
    void anOtherSlot(int, QObject *);
};

#endif // MYRECEIVER_H
