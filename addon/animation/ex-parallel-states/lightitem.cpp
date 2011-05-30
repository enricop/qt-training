/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QBrush>
#include "lightitem.h"

LightItem::LightItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent)
{
    m_brightness = 0.25;
    m_color = QColor(255, 255, 255);
    updateBrush();
}

qreal LightItem::brightness() const
{
    return m_brightness;
}

void LightItem::setBrightness(qreal brightness)
{
    m_brightness = qBound(0.0, brightness, 1.0);
    updateBrush();
}

QColor LightItem::color() const
{
    return m_color;
}

void LightItem::setColor(const QColor &color)
{
    m_color = color;
    updateBrush();
}

void LightItem::updateBrush()
{
    setBrush(QBrush(QColor(m_color.red() * m_brightness,
                           m_color.green() * m_brightness,
                           m_color.blue() * m_brightness)));
}

#include <QDebug>

void LightItem::debug()
{
    qDebug() << sender();
}
