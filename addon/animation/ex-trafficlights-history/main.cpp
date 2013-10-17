/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Information (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
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
