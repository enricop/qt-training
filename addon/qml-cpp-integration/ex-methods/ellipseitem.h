/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QQuickPaintedItem>

class EllipseItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    EllipseItem(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    const QColor color() const;
    void setColor(const QColor &newColor);

    Q_INVOKABLE QColor randomColor() const;

signals:
    void colorChanged();
    void ready();

private:
    QColor m_color;
};

#endif
