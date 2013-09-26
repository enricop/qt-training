#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include "compass.h"

const double margin = 8.0;

Compass::Compass(QWidget *parent) : QWidget(parent)
{
}

double Compass::direction()
{
    // TODO: implement
    return 0.0;
}

void Compass::setDirection(double d)
{
    // TODO: implement
}


QSize Compass::sizeHint() const
{
    // TODO: implement
    return QSize();
}

void Compass::mousePressEvent(QMouseEvent *event)
{
    // TODO: implement
}

void Compass::paintEvent(QPaintEvent*)
{
    // TODO: implement
}
