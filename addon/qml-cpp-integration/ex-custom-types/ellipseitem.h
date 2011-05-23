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

#include <QDeclarativeItem>

class EllipseItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(Style style READ style WRITE setStyle NOTIFY styleChanged)
    Q_ENUMS(Style)

public:
    enum Style {
        Outline,
        Filled
    };

    EllipseItem(QDeclarativeItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

    const QColor &color() const;
    void setColor(const QColor &newColor);
    const Style &style() const;
    void setStyle(const Style &newStyle);

signals:
    void colorChanged();
    void styleChanged();

private:
    QColor m_color;
    Style m_style;
};

#endif
