/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "lightitem.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsView view;
    view.setBackgroundBrush(Qt::black);
    QGraphicsScene scene;
    view.setScene(&scene);
    view.setRenderHints(QPainter::Antialiasing);

    LightItem *upButton = new LightItem(-50, -150, 100, 100);
    upButton->setColor(Qt::blue);
    scene.addItem(upButton);
    LightItem *downButton = new LightItem(-50, 50, 100, 100);
    downButton->setColor(Qt::yellow);
    scene.addItem(downButton);
    LightItem *leftButton = new LightItem(-150, -50, 100, 100);
    leftButton->setColor(Qt::red);
    scene.addItem(leftButton);
    LightItem *rightButton = new LightItem(50, -50, 100, 100);
    rightButton->setColor(Qt::green);
    scene.addItem(rightButton);

    QStateMachine machine;

    QState *runningState = new QState(QState::ParallelStates);
    QState *horizontalState = new QState(runningState);
    QState *verticalState = new QState(runningState);

    QState *hcenterState = new QState(horizontalState);
    QState *leftState = new QState(horizontalState);
    QState *rightState = new QState(horizontalState);
    horizontalState->setInitialState(hcenterState);

    QState *vcenterState = new QState(verticalState);
    QState *upState = new QState(verticalState);
    QState *downState = new QState(verticalState);
    verticalState->setInitialState(vcenterState);

    QFinalState *finishedState = new QFinalState();

    // Add the top-level states to the machine.
    machine.addState(runningState);
    machine.addState(finishedState);
    machine.setInitialState(runningState);

    // Assign properties for each state.
    runningState->assignProperty(&view, "visible", true);

    vcenterState->assignProperty(upButton, "brightness", 0.25);
    vcenterState->assignProperty(downButton, "brightness", 0.25);

    upState->assignProperty(upButton, "brightness", 1.0);
    upState->assignProperty(downButton, "brightness", 0.25);

    downState->assignProperty(upButton, "brightness", 0.25);
    downState->assignProperty(downButton, "brightness", 1.0);

    hcenterState->assignProperty(leftButton, "brightness", 0.25);
    hcenterState->assignProperty(rightButton, "brightness", 0.25);

    leftState->assignProperty(leftButton, "brightness", 1.0);
    leftState->assignProperty(rightButton, "brightness", 0.25);

    rightState->assignProperty(leftButton, "brightness", 0.25);
    rightState->assignProperty(rightButton, "brightness", 1.0);

    // Add transitions.
    QKeyEventTransition *up = new QKeyEventTransition(&view, QEvent::KeyPress, Qt::Key_Up);
    up->setTargetState(upState);
    vcenterState->addTransition(up);
                
    QKeyEventTransition *upCenter = new QKeyEventTransition(&view, QEvent::KeyRelease, Qt::Key_Up);
    upCenter->setTargetState(vcenterState);
    upState->addTransition(upCenter);

    QKeyEventTransition *down = new QKeyEventTransition(&view, QEvent::KeyPress, Qt::Key_Down);
    down->setTargetState(downState);
    vcenterState->addTransition(down);

    QKeyEventTransition *downCenter = new QKeyEventTransition(&view, QEvent::KeyRelease, Qt::Key_Down);
    downCenter->setTargetState(vcenterState);
    downState->addTransition(downCenter);

    QKeyEventTransition *left = new QKeyEventTransition(&view, QEvent::KeyPress, Qt::Key_Left);
    left->setTargetState(leftState);
    hcenterState->addTransition(left);

    QKeyEventTransition *leftCenter = new QKeyEventTransition(&view, QEvent::KeyRelease, Qt::Key_Left);
    leftCenter->setTargetState(hcenterState);
    leftState->addTransition(leftCenter);

    QKeyEventTransition *right = new QKeyEventTransition(&view, QEvent::KeyPress, Qt::Key_Right);
    right->setTargetState(rightState);
    hcenterState->addTransition(right);

    QKeyEventTransition *rightCenter = new QKeyEventTransition(&view, QEvent::KeyRelease, Qt::Key_Right);
    rightCenter->setTargetState(hcenterState);
    rightState->addTransition(rightCenter);

    QObject::connect(&machine, SIGNAL(finished()), &app, SLOT(quit()));
    machine.start();

    return app.exec();
}
