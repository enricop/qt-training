/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    QSpinBox *spin = new QSpinBox;

    QObject::connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);

    // slider and spin are connected, change will be propagated to spinbox
    slider->setValue(40);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spin);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
