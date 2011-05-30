/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "graphicspixmapitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    GraphicsPixmapItem icon(QPixmap(":/icons/logo.png"));
    icon.setPos(0, 0);
    scene.addItem(&icon);

    QPainterPath path;
    path.moveTo(0, 0);
    path.lineTo(200, 50);
    path.lineTo(150, 250);
    path.lineTo(-50, 200);
    path.closeSubpath();
    QGraphicsPathItem track(path);
    scene.addItem(&track);

    QGraphicsView view;
    view.setScene(&scene);
    view.resize(480, 360);
    view.show();

    QStateMachine machine;
    QState *topState = new QState();
    QState *rightState = new QState();
    QState *bottomState = new QState();
    QState *leftState = new QState();

    topState->assignProperty(&icon, "pos", QPointF(0, 0));
    rightState->assignProperty(&icon, "pos", QPointF(200, 50));
    bottomState->assignProperty(&icon, "pos", QPointF(150, 250));
    leftState->assignProperty(&icon, "pos", QPointF(-50, 200));

    QTimer timer;
    timer.start(2500);

    QAbstractTransition *topTransition = topState->addTransition(&timer, SIGNAL(timeout()), rightState);
    QAbstractTransition *rightTransition = rightState->addTransition(&timer, SIGNAL(timeout()), bottomState);
    QAbstractTransition *bottomTransition = bottomState->addTransition(&timer, SIGNAL(timeout()), leftState);
    QAbstractTransition *leftTransition = leftState->addTransition(&timer, SIGNAL(timeout()), topState);

    QPropertyAnimation *animation = new QPropertyAnimation(&icon, "pos");
    animation->setDuration(2500);
    topTransition->addAnimation(animation);
    rightTransition->addAnimation(animation);
    bottomTransition->addAnimation(animation);
    leftTransition->addAnimation(animation);

    machine.addState(topState);
    machine.addState(rightState);
    machine.addState(bottomState);
    machine.addState(leftState);
    machine.setInitialState(topState);

    machine.start();
    return app.exec();
}
