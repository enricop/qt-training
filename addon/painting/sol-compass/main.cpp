#include <QApplication>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QWidget>

#include "compass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget();

    QVBoxLayout *layout = new QVBoxLayout(window);
    Compass *compass = new Compass();
    layout->addWidget(compass);
    QDoubleSpinBox *spinbox = new QDoubleSpinBox();
    spinbox->setRange(0.0, 360.0);
    layout->addWidget(spinbox);

    window->connect(compass, SIGNAL(directionChanged(double)),
                     spinbox, SLOT(setValue(double)));
    window->connect(spinbox, SIGNAL(valueChanged(double)),
                     compass, SLOT(setDirection(double)));

    window->show();

    return app.exec();
}
