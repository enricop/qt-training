/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
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
private:
	QGraphicsLineItem* m_rod;
	QGraphicsEllipseItem* m_weight;
};

#endif /* PENDULUMITEM_H */

