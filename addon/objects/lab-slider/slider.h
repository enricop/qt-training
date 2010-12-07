#ifndef SLIDER_H
#define SLIDER_H

#include <QtGui>

class QLabel;
class QSlider;

class Slider : public QWidget
{
public:
    Slider(Qt::Orientation orient = Qt::Horizontal, QWidget *parent = 0);
};

#endif // SLIDER_H
