/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include "graphicsrectitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    GraphicsRectItem rectangle(0, 0, 20, 20);
    rectangle.setBrush(Qt::red);
    scene.addItem(&rectangle);

    QGraphicsView view;
    view.setScene(&scene);
    view.resize(480, 360);
    view.show();

    QPropertyAnimation animation(&rectangle, "geometry");
    animation.setDuration(10000);
    animation.setStartValue(QRect(0, 0, 100, 30));
    animation.setEndValue(QRect(250, 250, 100, 30));

    animation.start();
    return app.exec();
}
