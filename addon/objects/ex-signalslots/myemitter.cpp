/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "myemitter.h"

MyEmitter::MyEmitter(const QString &label, QWidget *parent)
    : QPushButton(label, parent)
{
    connect(this, SIGNAL(clicked()), this, SIGNAL(aSignal()));
}
