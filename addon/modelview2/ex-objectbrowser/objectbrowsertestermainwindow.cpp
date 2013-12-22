#include "objectbrowsertestermainwindow.h"
#include "ui_objectbrowsertestermainwindow.h"
#include "qobjectbrowseraction.h"

ObjectBrowserTesterMainWindow::ObjectBrowserTesterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ObjectBrowserTesterMainWindow)
{
    ui->setupUi(this);
    gallery = new Ui::Gallery();
    hostWidget = new QWidget();
    gallery->setupUi(hostWidget);
    setCentralWidget(hostWidget);
    ui->menuFile->addAction(new QObjectBrowserAction(this));


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
