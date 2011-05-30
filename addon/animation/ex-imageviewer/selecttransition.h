/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SELECTTRANSITION_H
#define SELECTTRANSITION_H

#include <QSignalTransition>

class SelectTransition : public QSignalTransition
{
public:
    SelectTransition(QState *sourceState = 0);

protected:
    bool eventTest(QEvent *event);
};

#endif
