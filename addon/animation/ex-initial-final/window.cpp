/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    nameEdit = new QLineEdit();
    connect(nameEdit, SIGNAL(returnPressed()), this, SLOT(processName()));

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(tr("Enter your name:"), nameEdit);
}

void Window::processName()
{
    emit nameEntered(nameEdit->text());
}
