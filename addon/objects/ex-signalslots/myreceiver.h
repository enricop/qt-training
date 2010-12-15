/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

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
