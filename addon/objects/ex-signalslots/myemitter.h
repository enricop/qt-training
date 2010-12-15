/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#include <QPushButton>

class MyEmitter : public QPushButton
{
    Q_OBJECT

public:
    MyEmitter(const QString &label, QWidget *parent = 0);

signals:
    void aSignal();
    void anOtherSignal(int, QWidget *);
};

#endif // MYSIGNAL_H
