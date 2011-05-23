/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLabel>

class StopWatch : public QLabel
{
    Q_OBJECT

public:
    StopWatch(QWidget *parent = 0);

protected slots:
    void shot();

private:
    int m_secs;
};

#endif
