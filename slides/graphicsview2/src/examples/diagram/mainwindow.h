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

