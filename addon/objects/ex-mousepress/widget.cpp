/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_clicked(false)
{}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        m_clicked = !m_clicked;

    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
    if (m_clicked) {
        painter.drawLine(rect().topLeft(), rect().bottomRight());
        painter.drawLine(rect().topRight(), rect().bottomLeft());
    }
    painter.end();
}
