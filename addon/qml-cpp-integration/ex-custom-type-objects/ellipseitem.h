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
#include "style.h"

class EllipseItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(Style *style READ style WRITE setStyle NOTIFY styleChanged)

public:
    EllipseItem(QDeclarativeItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

    Style *style() const;
    void setStyle(Style *newStyle);

signals:
    void styleChanged();

private:
    Style *m_style;
};

#endif
