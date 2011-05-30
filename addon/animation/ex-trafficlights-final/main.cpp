/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#ifdef QT_STATEMACHINE_SOLUTION
#include <qstate.h>
#include <qstatemachine.h>
#endif

#include "lightwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::black);
    window.setPalette(palette);

    LightWidget *redLight = new LightWidget(Qt::red);
    LightWidget *amberLight = new LightWidget(Qt::yellow);
    LightWidget *greenLight = new LightWidget(Qt::green);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(redLight);
    layout->addWidget(amberLight);
    layout->addWidget(greenLight);
    window.setLayout(layout);

    QStateMachine machine;

    QState *runningState = new QState();
    QState *stopState = new QState(runningState);
    QState *waitState = new QState(runningState);
    QState *driveState = new QState(runningState);
    QFinalState *childFinalState = new QFinalState(runningState);
    runningState->setInitialState(stopState);

    QFinalState *finishedState = new QFinalState();

    // Add the top-level states to the machine.
    machine.addState(runningState);
    machine.addState(finishedState);
    machine.setInitialState(runningState);

    // Assign properties for each state.
    runningState->assignProperty(&window, "visible", true);

    stopState->assignProperty(redLight, "on", true);
    stopState->assignProperty(amberLight, "on", false);
    stopState->assignProperty(greenLight, "on", false);

    waitState->assignProperty(redLight, "on", true);
    waitState->assignProperty(amberLight, "on", true);
    waitState->assignProperty(greenLight, "on", false);

    driveState->assignProperty(redLight, "on", false);
    driveState->assignProperty(amberLight, "on", false);
    driveState->assignProperty(greenLight, "on", true);

    // Add transitions.
    QTimer timer;
    timer.start(2000);

    stopState->addTransition(&timer, SIGNAL(timeout()), waitState);
    waitState->addTransition(&timer, SIGNAL(timeout()), driveState);
    driveState->addTransition(&timer, SIGNAL(timeout()), childFinalState);
    runningState->addTransition(runningState, SIGNAL(finished()), finishedState);

    QObject::connect(&machine, SIGNAL(finished()), &app, SLOT(quit()));
    machine.start();

    return app.exec();
}
