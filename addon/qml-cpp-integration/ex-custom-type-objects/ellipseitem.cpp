/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "ellipseitem.h"

EllipseItem::EllipseItem(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void EllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget * /*widget*/)
{
    painter->save();
    if (!m_style->filled()) {
        painter->setPen(m_style->color());
        painter->setBrush(Qt::NoBrush);
    } else {
        painter->setPen(Qt::NoPen);
        painter->setBrush(m_style->color());
    }
    painter->drawEllipse(option->rect);
    painter->restore();
}

Style *EllipseItem::style() const
{
    return m_style;
}

void EllipseItem::setStyle(Style *newStyle)
{
    if (m_style != newStyle) {
        m_style = newStyle;
        m_style->setParentItem(this);
        emit styleChanged();
        update();
    }
}
