/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

/* -*-C++-*- */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ToolBox;
class QGraphicsView;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow( QWidget* parent = 0 );
private:
    ToolBox* m_toolbox;
    QGraphicsView* m_view;
};

#endif /* MAINWINDOW_H */

