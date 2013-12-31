#ifndef OBJECTBROWSERTESTERMAINWINDOW_H
#define OBJECTBROWSERTESTERMAINWINDOW_H

#include <QMainWindow>


namespace Ui {
    class ObjectBrowserTesterMainWindow;
    class Gallery;
}

class ObjectBrowserTesterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ObjectBrowserTesterMainWindow(QWidget *parent = 0);
    ~ObjectBrowserTesterMainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_actionQuit_triggered();

private:
    Ui::ObjectBrowserTesterMainWindow *ui;
    Ui::Gallery *gallery;

};

#endif // OBJECTBROWSERTESTERMAINWINDOW_H
