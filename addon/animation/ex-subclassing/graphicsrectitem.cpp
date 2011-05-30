/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "graphicsrectitem.h"

GraphicsRectItem::GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
}

QRectF GraphicsRectItem::geometry() const
{
    return rect();
}

void GraphicsRectItem::setGeometry(const QRectF &rectangle)
{
    setRect(rectangle);
}
