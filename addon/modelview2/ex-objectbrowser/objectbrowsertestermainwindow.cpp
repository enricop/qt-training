#include "objectbrowsertestermainwindow.h"
#include "ui_gallery.h"
#include "ui_objectbrowsertestermainwindow.h"
#include "qobjectbrowseraction.h"

ObjectBrowserTesterMainWindow::ObjectBrowserTesterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ObjectBrowserTesterMainWindow)
{
    ui->setupUi(this);
    gallery = new Ui::Gallery();
    QWidget* hostWidget = new QWidget();
    gallery->setupUi(hostWidget);
    setCentralWidget(hostWidget);
    ui->menuView->addAction(new QObjectBrowserAction(this));


}

ObjectBrowserTesterMainWindow::~ObjectBrowserTesterMainWindow()
{
    delete ui;
}

void ObjectBrowserTesterMainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ObjectBrowserTesterMainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}
