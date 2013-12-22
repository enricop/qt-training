#ifndef OBJECTBROWSERTESTERMAINWINDOW_H
#define OBJECTBROWSERTESTERMAINWINDOW_H

#include <QMainWindow>
#include "ui_gallery.h"

namespace Ui {
class ObjectBrowserTesterMainWindow;
}

class ObjectBrowserTesterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ObjectBrowserTesterMainWindow(QWidget *parent = 0);
    ~ObjectBrowserTesterMainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ObjectBrowserTesterMainWindow *ui;
    Ui::Gallery *gallery;
    QWidget *hostWidget;
};

#endif // OBJECTBROWSERTESTERMAINWINDOW_H
