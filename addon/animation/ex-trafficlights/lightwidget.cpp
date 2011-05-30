/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

#include "lightwidget.h"

LightWidget::LightWidget(const QColor &color, QWidget *parent)
    : QWidget(parent)
{
    this->color = color;
    m_on = false;
}

void LightWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), Qt::black);
    if (m_on) {
        painter.setBrush(color);
        painter.drawEllipse(rect());
    }
}

bool LightWidget::isOn() const
{
    return m_on;
}

void LightWidget::setOn(bool enable)
{
    if (enable == m_on)
        return;
    m_on = enable;
    update();
}

QSize LightWidget::sizeHint() const
{
    return QSize(100, 100);
}
