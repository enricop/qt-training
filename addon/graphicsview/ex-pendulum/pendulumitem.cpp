/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "pendulumitem.h"

#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QRadialGradient>
#include <QPainter>

static const int PENWIDTH = 3;

PendulumItem::PendulumItem(QGraphicsItem* parent)
  : QGraphicsItemGroup(parent) { 
  m_rod = new QGraphicsLineItem( 0,0,0,100, this);
  m_rod->setPen( QPen( Qt::black, 3 ) );
  m_weight = new QGraphicsEllipseItem( -20, 100, 40, 40, this );
  m_weight->setPen( QPen(Qt::black, 3 ));

  QRadialGradient g( 0, 120, 20, -10, 110 );
  g.setColorAt( 0.0, Qt::white );
  g.setColorAt( 0.5, Qt::yellow );
  g.setColorAt( 1.0, Qt::black );
  m_weight->setBrush(g);  
}

PendulumItem::~PendulumItem() { }

