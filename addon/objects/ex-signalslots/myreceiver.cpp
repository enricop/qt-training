/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "myreceiver.h"

MyReceiver::MyReceiver(QObject *parent)
    : QObject(parent)
{}

void MyReceiver::aSlot()
{
    qDebug("A Slot");
}

void MyReceiver::anOtherSlot(int, QObject *)
{
    qDebug("anOtherSlot");
}
