/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPolygonItem>

class DiagramItem : public QGraphicsPolygonItem {
public:
    typedef QGraphicsPolygonItem BASE;
    enum ItemType { TYPE_BOX, TYPE_TRIANGLE, TYPE_PENTAGON, TYPE_ELLIPSE, TYPE_TEXT } ;

    explicit DiagramItem( const QRectF& );
    explicit DiagramItem( const QPolygonF& );
    static DiagramItem* createItem( DiagramItem::ItemType type );

    ItemType itemType() const {
        return m_type;
    }

protected:
    /*** Event handlers used for resizing the item ***/
    /*reimp*/void hoverMoveEvent(QGraphicsSceneHoverEvent*);
    /*reimp*/void mousePressEvent(QGraphicsSceneMouseEvent*);
    /*reimp*/void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    /*reimp*/void mouseMoveEvent(QGraphicsSceneMouseEvent*);

    /*** Event handlers used for DnD ***/
    /*reimp*/void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    /*reimp*/void dropEvent(QGraphicsSceneDragDropEvent*);

private:
    void init();
    QPainterPath outline() const;

    QPointF m_pressPos;
    QPolygonF m_polygon;

    ItemType m_type;
};

#endif /* DIAGRAMITEM_H */

