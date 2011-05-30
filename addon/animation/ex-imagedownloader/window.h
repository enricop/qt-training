/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QState>
#include <QWidget>
#include <QXmlStreamReader>

#include "pipeline.h"
#include "ui_downloadwidget.h"

class QAbstractGraphicsShapeItem;
class QNetworkAccessManager;
class QNetworkReply;
class QStateMachine;

class Window : public QWidget, private Ui::DownloadWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

signals:
    void parseComplete();
    void parseError();

private slots:
    void on();
    void off();
    void on_urlButton_clicked();
    void on_urlEdit_returnPressed();
    void parseData();
    void readData();

private:
    Pipeline pipeline;
    QGraphicsScene *scene;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QStateMachine *machine;
    QXmlStreamReader reader;
    QHash<QState *,QAbstractGraphicsShapeItem *> items;
};

#endif
