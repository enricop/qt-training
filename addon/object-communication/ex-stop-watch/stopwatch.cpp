/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "stopwatch.h"

StopWatch::StopWatch(QWidget *parent)
    : QLabel(parent), m_secs(0)
{
    setText("0:00");

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(shot()));
}

void StopWatch::shot()
{
    m_secs += 1;
    QString str;
    str.sprintf( "%d:%02d", m_secs / 60, m_secs % 60 );
    setText( str );
}
