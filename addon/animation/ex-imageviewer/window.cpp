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
