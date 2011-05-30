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
    QPushButton *pauseButton = new QPushButton(QApplication::translate(
        "trafficlights", "Pause"));
    pauseButton->setCheckable(true);
    QPushButton *quitButton = new QPushButton(QApplication::translate(
        "trafficlights", "Quit"));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(redLight);
    layout->addWidget(amberLight);
    layout->addWidget(greenLight);
    layout->addWidget(pauseButton);
    layout->addWidget(quitButton);
    window.setLayout(layout);

    QStateMachine machine;

    QState *runningState = new QState();
    QState *stopState = new QState(runningState);
    QState *waitState = new QState(runningState);
    QState *driveState = new QState(runningState);
    QState *slowState = new QState(runningState);
    runningState->setInitialState(stopState);

    QHistoryState *historyState = new QHistoryState(runningState);
    QState *pausedState = new QState();
    QFinalState *finishedState = new QFinalState();

    // Add the top-level states to the machine.
    machine.addState(runningState);
    machine.addState(pausedState);
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

    slowState->assignProperty(redLight, "on", false);
    slowState->assignProperty(amberLight, "on", true);
    slowState->assignProperty(greenLight, "on", false);

    // Add transitions.
    QTimer timer;
    timer.start(2000);

    stopState->addTransition(&timer, SIGNAL(timeout()), waitState);
    waitState->addTransition(&timer, SIGNAL(timeout()), driveState);
    driveState->addTransition(&timer, SIGNAL(timeout()), slowState);
    slowState->addTransition(&timer, SIGNAL(timeout()), stopState);

    runningState->addTransition(quitButton, SIGNAL(clicked()), finishedState);
    runningState->addTransition(pauseButton, SIGNAL(toggled(bool)), pausedState);
    pausedState->addTransition(pauseButton, SIGNAL(toggled(bool)), historyState);

    QObject::connect(&machine, SIGNAL(finished()), &app, SLOT(quit()));
    machine.start();

    return app.exec();
}
