/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QGraphicsPolygonItem>

#include "diagramscene.h"


DiagramScene::DiagramScene( QObject* parent )
    : QGraphicsScene( parent )
{
}

void DiagramScene::dragMoveEvent( QGraphicsSceneDragDropEvent* event )
{
     if (event->mimeData()->hasFormat("application/x-qgraphicsitem-ptr"))
         event->acceptProposedAction();
     else
         /* Call baseclass to allow per-item dragMoveEvent */
         QGraphicsScene::dragMoveEvent( event );
}

void DiagramScene::dropEvent( QGraphicsSceneDragDropEvent* event )
{
    if (event->mimeData()->hasFormat("application/x-qgraphicsitem-ptr")) {
         QGraphicsItem* item = reinterpret_cast<QGraphicsItem*>( event->mimeData()->data("application/x-qgraphicsitem-ptr").toULongLong() );
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
