/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PENDULUMITEM_H
#define PENDULUMITEM_H

#include <QGraphicsItemGroup>

class QGraphicsLineItem;
class QGraphicsEllipseItem;

class PendulumItem : public QGraphicsItemGroup {
public:
  PendulumItem( QGraphicsItem* parent=0);
  virtual ~PendulumItem();
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  QPainterPath shape() const;
  QRectF boundingRect() const;
private:
	QGraphicsLineItem* m_rod;
	QGraphicsEllipseItem* m_weight;
    QPainterPath m_shape;
    QRectF m_boundingRect;
};

#endif /* PENDULUMITEM_H */

