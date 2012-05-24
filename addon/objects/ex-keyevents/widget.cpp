/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);

    // Ensure that the window is large enough to display our messages.
    QFontMetrics metrics(font());
    QRect messageRect1 = metrics.boundingRect(tr("Key pressed: ''"));
    QRect messageRect2 = metrics.boundingRect(tr("Key released: ''"));
    QRect totalRect = messageRect1.united(messageRect2);

    resize( totalRect.width()  + metrics.maxWidth(),
            totalRect.height() + metrics.height()    );

    setWindowTitle(tr("Key Events"));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    QString key = static_cast<QKeyEvent *>(event)->text();
    m_text = tr("Key pressed: '%1'").arg(key);
    event->accept();
    update();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    QString key = static_cast<QKeyEvent *>(event)->text();
    m_text = tr("Key released: '%1'").arg(key);
    event->accept();
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);
    painter.drawText(rect(), Qt::AlignCenter, m_text);
    painter.end();
}
