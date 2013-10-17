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
#include <QtNetwork>

#include "pipeline.h"
#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    manager = new QNetworkAccessManager(this);
    machine = new QStateMachine(this);

    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);
}

void Window::on_urlEdit_returnPressed()
{
    on_urlButton_clicked();
}

void Window::on_urlButton_clicked()
{
    reader.clear();
    pipeline.clear();
    imageList->clear();

    QNetworkRequest request(QUrl(urlEdit->text()));
    reply = manager->get(request);

    machine->deleteLater();
    machine = new QStateMachine(this);

    QState *runningState = new QState(QState::ParallelStates);

    QState *downloadingState = new QState(runningState);
    QState *readingState = new QState(downloadingState);
    QState *waitingState = new QState(downloadingState);
    downloadingState->setInitialState(waitingState);

    QState *showingState = new QState(runningState);
    QState *parsingState = new QState(showingState);
    QState *pendingState = new QState(showingState);
    showingState->setInitialState(pendingState);

    QFinalState *finishedState = new QFinalState();

    // Add the top-level states to the machine.
    machine->addState(runningState);
    machine->addState(finishedState);
    machine->setInitialState(runningState);

    waitingState->addTransition(reply, SIGNAL(readyRead()), readingState);
    connect(readingState, SIGNAL(entered()), this, SLOT(readData()));
    readingState->addTransition(waitingState);
    //readingState->addTransition(reply, SIGNAL(readyRead()), readingState);

    pendingState->addTransition(&pipeline, SIGNAL(readyRead()), parsingState);
    connect(parsingState, SIGNAL(entered()), this, SLOT(parseData()));
    parsingState->addTransition(pendingState);

    runningState->addTransition(this, SIGNAL(parseComplete()), finishedState);
    runningState->addTransition(reply, SIGNAL(error()), finishedState);
    runningState->addTransition(this, SIGNAL(parseError()), finishedState);

    connect(downloadingState, SIGNAL(entered()), this, SLOT(on()));
    connect(readingState, SIGNAL(entered()), this, SLOT(on()));
    connect(waitingState, SIGNAL(entered()), this, SLOT(on()));
    connect(showingState, SIGNAL(entered()), this, SLOT(on()));
    connect(parsingState, SIGNAL(entered()), this, SLOT(on()));
    connect(pendingState, SIGNAL(entered()), this, SLOT(on()));

    connect(downloadingState, SIGNAL(exited()), this, SLOT(off()));
    connect(readingState, SIGNAL(exited()), this, SLOT(off()));
    connect(waitingState, SIGNAL(exited()), this, SLOT(off()));
    connect(showingState, SIGNAL(exited()), this, SLOT(off()));
    connect(parsingState, SIGNAL(exited()), this, SLOT(off()));
    connect(pendingState, SIGNAL(exited()), this, SLOT(off()));

    items.clear();
    items[runningState] = scene->addEllipse(-10, -50, 230, 180);
    items[downloadingState] = scene->addEllipse(0, 0, 100, 80);
    items[readingState] = scene->addEllipse(5, 20, 40, 40);
    items[waitingState] = scene->addEllipse(55, 20, 40, 40);
    items[showingState] = scene->addEllipse(110, 0, 100, 80);
    items[parsingState] = scene->addEllipse(115, 20, 40, 40);
    items[pendingState] = scene->addEllipse(165, 20, 40, 40);

    foreach (QAbstractGraphicsShapeItem *item, items.values())
        item->setBrush(Qt::white);

    machine->start();
}

void Window::on()
{
    QState *state = qobject_cast<QState *>(sender());
    QAbstractGraphicsShapeItem *item = items[state];
    item->setBrush(Qt::red);
}

void Window::off()
{
    QState *state = qobject_cast<QState *>(sender());
    QAbstractGraphicsShapeItem *item = items[state];
    item->setBrush(Qt::white);
}

void Window::readData()
{
    QByteArray bytes = reply->readAll();
    pipeline.enqueue(bytes);
}

void Window::parseData()
{
    QXmlStreamReader::TokenType token;

    while (!pipeline.isEmpty()) {
        QByteArray data = pipeline.dequeue();
        reader.addData(data);
        do {
            token = reader.readNext();
            if (token == QXmlStreamReader::StartElement) {
                if (reader.name() == "img")
                    imageList->addItem(reader.attributes().value("src").toString());
            }
        } while (!reader.atEnd());

        if (reader.error() != QXmlStreamReader::NoError && reader.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
            emit parseError();
            return;
        }
    }

    if (token == QXmlStreamReader::EndDocument)
        emit parseComplete();
}
