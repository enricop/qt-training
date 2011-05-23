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

public:
    EllipseItem(QDeclarativeItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
};

#endif
