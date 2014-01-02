/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "pendulumitem.h"

#include <QGraphicsLineItem>
#include <QPainterPath>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QRadialGradient>
#include <QPainter>

static const int PENWIDTH = 3;

PendulumItem::PendulumItem(QGraphicsItem* parent)
  : QGraphicsItemGroup(parent) { 
  m_rod = new QGraphicsLineItem( 0,0,0,100, this);
  m_rod->setPen( QPen( Qt::black, PENWIDTH ) );
  m_weight = new QGraphicsEllipseItem( -20, 100, 40, 40, this );
  m_weight->setPen( QPen(Qt::black, PENWIDTH ));

  QRadialGradient g( 0, 120, 20, -10, 110 );
  g.setColorAt( 0.0, Qt::white );
  g.setColorAt( 0.5, Qt::yellow );
  g.setColorAt( 1.0, Qt::black );
  m_weight->setBrush(g);

  // join QPainterPaths together to get the whole shape:
  m_shape = m_rod->shape() + m_weight->shape();
  // Brush width adjustment:
  double bradj = (PENWIDTH / 2.0) + 4.0;
  // Pre-calculate the bounding rect too:
  m_boundingRect = m_shape.controlPointRect().adjusted(-bradj, -bradj, bradj, bradj);
}

PendulumItem::~PendulumItem() { }

void PendulumItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsItemGroup::paint(painter, option, widget);

    // Show the control point rectangle in blue-dashes. 
    QRectF rect = shape().controlPointRect().adjusted(-4,-4, 4, 4);
    QPen p = painter->pen();
    p.setStyle(Qt::DashLine);
    p.setColor(Qt::blue);
    painter->setPen(p);
    painter->drawRect(rect);
}

QRectF PendulumItem::boundingRect() const {
    return m_boundingRect;
}

QPainterPath PendulumItem::shape() const {
    return m_shape;
}
