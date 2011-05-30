/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
class QLineEdit;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

signals:
    void nameEntered(const QString &name);

private slots:
    void processName();

private:
    QLineEdit *nameEdit;
};

#endif
