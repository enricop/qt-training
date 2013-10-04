#include <QCheckBox>
#include <QTreeView>
#include <QVBoxLayout>

#include "window.h"
#include "widgetmodel.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QTreeView *view = new QTreeView();
    layout->addWidget(view);

    QCheckBox *showbutton = new QCheckBox("Show widgets");
    layout->addWidget(showbutton);

    // create gallery
    QWidget *hostwidget = new QWidget();
    gallery = new Ui::Gallery();
    gallery->setupUi(hostwidget);
    hostwidget->setVisible(false);

    connect(showbutton, &QCheckBox::toggled, hostwidget, &QWidget::setVisible);

    // create model
    WidgetModel *model = new WidgetModel(this);
    model->setRootWidget(hostwidget);
    view->setModel(model);
}

Window::~Window()
{
    delete gallery;
}
