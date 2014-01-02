/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QGraphicsPolygonItem>

#include "diagramscene.h"
#include "diagramitem.h"


DiagramScene::DiagramScene( QObject* parent )
    : QGraphicsScene( parent )
{
}

void DiagramScene::dragMoveEvent( QGraphicsSceneDragDropEvent* event )
{
     if (event->mimeData()->hasFormat("application/x-qgraphicsitem-typeid"))
         event->acceptProposedAction();
     else
         /* Call baseclass to allow per-item dragMoveEvent */
         QGraphicsScene::dragMoveEvent( event );
}

void DiagramScene::dropEvent( QGraphicsSceneDragDropEvent* event )
{
    if (event->mimeData()->hasFormat("application/x-qgraphicsitem-typeid")) {
         DiagramItem::ItemType typeId = (DiagramItem::ItemType) event->mimeData()->data("application/x-qgraphicsitem-typeid").toInt() ;
         DiagramItem *item = DiagramItem::createItem(typeId);
         if ( item ) {
             addItem( item );
             item->setFlag( QGraphicsItem::ItemIsMovable );
             item->setFlag( QGraphicsItem::ItemIsSelectable );
             item->setFlag( QGraphicsItem::ItemIsFocusable );
             item->setPos( event->scenePos() );
             event->acceptProposedAction();
         }
    } else
         /* Call baseclass to allow per-item dropEvent */
        QGraphicsScene::dropEvent( event );
}

