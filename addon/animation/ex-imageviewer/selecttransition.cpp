/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "selecttransition.h"

Q_DECLARE_METATYPE(QModelIndex)

SelectTransition::SelectTransition(QState *sourceState)
    : QSignalTransition(sourceState)
{
}

bool SelectTransition::eventTest(QEvent *event)
{
    if (!QSignalTransition::eventTest(event))
        return false;

    QStateMachine::SignalEvent *e = static_cast<QStateMachine::SignalEvent*>(event);

    QVariant argument = e->arguments()[0];
    QModelIndex index = qvariant_cast<QModelIndex>(argument);
    return index.isValid();
}
