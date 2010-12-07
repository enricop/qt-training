#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    QSpinBox *spin = new QSpinBox;

    QObject::connect(slider, SIGNAL(valueChanged(int)), spin, SLOT(setValue(int)));

    // slider and spin are connected, change will be propagated to spinbox
    slider->setValue(40);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spin);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
