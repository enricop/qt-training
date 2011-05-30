/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton();
    QStateMachine *machine = new QStateMachine();

    QState *offState = new QState();
    offState->assignProperty(button, "text", "Off");

    QState *onState = new QState();
    onState->assignProperty(button, "text", "On");

    offState->addTransition(button, SIGNAL(clicked()), onState);
    onState->addTransition(button, SIGNAL(clicked()), offState);

    machine->addState(offState);
    machine->addState(onState);

    machine->setInitialState(offState);
    machine->start();

    button->resize(100, 50);
    button->show();
    return app.exec();
}
