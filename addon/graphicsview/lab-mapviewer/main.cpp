/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MapViewerItem.h"
#include "MapControllerItem.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QGraphicsScene scene( -300.0, -200.0, 600.0, 400.0 ); // centered on (0.0, 0.0)

    MapViewerItem* mapViewerItem = new MapViewerItem;
    scene.addItem( mapViewerItem );
    
    // Add MapControllerItem to the scene

    QGraphicsView view( &scene );
    view.setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view.setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view.resize(600,400);
    view.show();
    return app.exec();
}
