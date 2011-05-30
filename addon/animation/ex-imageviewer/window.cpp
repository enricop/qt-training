/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

#include "selecttransition.h"
#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    dirPath = QDir::currentPath();

    QStringList patterns;
    foreach (QByteArray format, QImageReader::supportedImageFormats())
        patterns.append("*."+format);

    dirModel = new QDirModel(patterns, QDir::AllEntries, QDir::Name);
    listView->setModel(dirModel);
    listView->setRootIndex(dirModel->index(dirPath));
    inputEdit->setText(QDir::currentPath());

    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);

    QStateMachine *machine = new QStateMachine(this);
    QFinalState *finishedState = new QFinalState();

    QState *runningState = new QState();
    QState *waitingState = new QState(runningState);
    QState *choosingState = new QState(runningState);
    QState *showingState = new QState(runningState);
    runningState->setInitialState(waitingState);

    waitingState->addTransition(inputButton, SIGNAL(clicked()), choosingState);
    connect(choosingState, SIGNAL(entered()), this, SLOT(chooseDirectory()));
    choosingState->addTransition(waitingState);

    SelectTransition *selectTransition = new SelectTransition(waitingState);
    selectTransition->setSenderObject(listView);
    selectTransition->setSignal(SIGNAL(clicked(const QModelIndex &)));
    selectTransition->setTargetState(showingState);

    connect(showingState, SIGNAL(entered()), this, SLOT(showImage()));
    showingState->addTransition(waitingState);

    machine->addState(runningState);
    machine->addState(finishedState);
    machine->setInitialState(runningState);
    machine->start();
};

void Window::chooseDirectory()
{
    QString path = QFileDialog::getExistingDirectory(this,
        tr("Choose Image Directory"), inputEdit->text());

    if (!path.isEmpty() && QFileInfo(path).isDir()) {
        listView->setRootIndex(dirModel->index(path));
        inputEdit->setText(path);
        dirPath = path;
    }
}

void Window::showImage()
{
    QModelIndex index = listView->selectionModel()->currentIndex();
    if (!index.isValid())
        return;

    QString name = index.data().toString();
    QString path = QFileInfo(dirPath, name).filePath();

    QPixmap pixmap(path);
    if (!pixmap.isNull()) {
        scene->clear();
        scene->setSceneRect(QRectF(QPointF(0, 0), pixmap.size()));
        scene->addItem(new QGraphicsPixmapItem(pixmap));
    }
}
