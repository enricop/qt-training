/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef LIGHTITEM_H
#define LIGHTITEM_H

#include <QColor>
#include <QGraphicsEllipseItem>
#include <QObject>

class LightItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(qreal brightness READ brightness WRITE setBrightness)
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    LightItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = 0);
    qreal brightness() const;
    void setBrightness(qreal brightness);
    QColor color() const;
    void setColor(const QColor &color);

public slots:
    void debug();

private:
    void updateBrush();

    QColor m_color;
    qreal m_brightness;
};

#endif
