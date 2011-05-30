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
#include "window.h"

Window::Window(QWidget *parent)
    : QGraphicsView(parent)
{
    setBackgroundBrush(Qt::black);
    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHints(QPainter::Antialiasing);

    LightItem *upButton = new LightItem(-50, -150, 100, 100);
    upButton->setColor(Qt::blue);
    scene->addItem(upButton);
    LightItem *downButton = new LightItem(-50, 50, 100, 100);
    downButton->setColor(Qt::yellow);
    scene->addItem(downButton);
    LightItem *leftButton = new LightItem(-150, -50, 100, 100);
    leftButton->setColor(Qt::red);
    scene->addItem(leftButton);
    LightItem *rightButton = new LightItem(50, -50, 100, 100);
    rightButton->setColor(Qt::green);
    scene->addItem(rightButton);

    QStateMachine *machine = new QStateMachine();

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
    machine->addState(runningState);
    machine->addState(finishedState);
    machine->setInitialState(runningState);

    // Assign properties for each state.
    runningState->assignProperty(this, "visible", true);

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

    // Add animations and transitions.
    QKeyEventTransition *upTransition;
    upTransition = new QKeyEventTransition(this,
                       QEvent::KeyPress, Qt::Key_Up);
    upTransition->setTargetState(upState);
    vcenterState->addTransition(upTransition);

    QKeyEventTransition *upCenterTransition;
    upCenterTransition = new QKeyEventTransition(this,
                             QEvent::KeyRelease, Qt::Key_Up);
    upCenterTransition->setTargetState(vcenterState);
    upState->addTransition(upCenterTransition);

    QPropertyAnimation *upAnimation;
    upAnimation = new QPropertyAnimation(upButton, "brightness", this);
    upAnimation->setDuration(1000);
    upTransition->addAnimation(upAnimation);
    upCenterTransition->addAnimation(upAnimation);
           
    QPropertyAnimation *downAnimation = new QPropertyAnimation(downButton, "brightness", this);
    downAnimation->setDuration(1000);

    QKeyEventTransition *downTransition = new QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_Down);
    downTransition->setTargetState(downState);
    downTransition->addAnimation(downAnimation);
    vcenterState->addTransition(downTransition);

    QKeyEventTransition *downCenterTransition = new QKeyEventTransition(this, QEvent::KeyRelease, Qt::Key_Down);
    downCenterTransition->setTargetState(vcenterState);
    downCenterTransition->addAnimation(downAnimation);
    downState->addTransition(downCenterTransition);

    QPropertyAnimation *leftAnimation = new QPropertyAnimation(leftButton, "brightness", this);
    leftAnimation->setDuration(1000);

    QKeyEventTransition *leftTransition = new QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_Left);
    leftTransition->setTargetState(leftState);
    leftTransition->addAnimation(leftAnimation);
    hcenterState->addTransition(leftTransition);

    QKeyEventTransition *leftCenterTransition = new QKeyEventTransition(this, QEvent::KeyRelease, Qt::Key_Left);
    leftCenterTransition->setTargetState(hcenterState);
    leftCenterTransition->addAnimation(leftAnimation);
    leftState->addTransition(leftCenterTransition);

    QPropertyAnimation *rightAnimation = new QPropertyAnimation(rightButton, "brightness", this);
    rightAnimation->setDuration(1000);

    QKeyEventTransition *rightTransition = new QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_Right);
    rightTransition->setTargetState(rightState);
    rightTransition->addAnimation(rightAnimation);
    hcenterState->addTransition(rightTransition);

    QKeyEventTransition *rightCenterTransition = new QKeyEventTransition(this, QEvent::KeyRelease, Qt::Key_Right);
    rightCenterTransition->setTargetState(hcenterState);
    rightCenterTransition->addAnimation(rightAnimation);
    rightState->addTransition(rightCenterTransition);

    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->start();

    setWindowTitle(tr("Parallel Animations"));
}
