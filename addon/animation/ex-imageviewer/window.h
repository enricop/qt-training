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

#include <QWidget>

class QDirModel;
class QGraphicsScene;

#include "ui_window.h"

class Window : public QWidget, private Ui::Window
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

private slots:
    void chooseDirectory();
    void showImage();

private:
    QDirModel *dirModel;
    QGraphicsScene *scene;
    QString dirPath;
};

#endif
