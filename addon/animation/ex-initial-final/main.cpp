/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Window *window = new Window();
    QStateMachine *machine = new QStateMachine();

    QState *questionState = new QState();
    QFinalState *answeredState = new QFinalState();

    questionState->assignProperty(window, "visible", true);
    questionState->addTransition(window, SIGNAL(nameEntered(QString)),
                                 answeredState);

    machine->addState(questionState);
    machine->addState(answeredState);

    machine->setInitialState(questionState);
    QObject::connect(machine, SIGNAL(finished()), &app, SLOT(quit()));
    machine->start();

    return app.exec();
}
