#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include "compass.h"

const double margin = 8.0;

Compass::Compass(QWidget *parent) : QWidget(parent), m_direction(0.0)
{
    setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,
                              QSizePolicy::MinimumExpanding));
    setMinimumSize(QSize(margin, margin));
}

double Compass::direction()
{
    return m_direction;
}

void Compass::setDirection(double d)
{
    if ((d >= 0.0) && (d <=360.0)) {
        m_direction = d;
        update();
        emit directionChanged(m_direction);
    }
}


QSize Compass::sizeHint() const
{
    // 128x128 is sufficient
    return QSize(128, 128);
}

void Compass::mousePressEvent(QMouseEvent *event)
{
    // calc angle between center and mouse position
    QLineF line(rect().center(), event->pos());
    m_direction = line.angle();
    m_direction -= 90.0; // we want zero to be north
    if (m_direction < 0.0) m_direction += 360.0;

    update();
    emit directionChanged(m_direction);
}

void Compass::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // setup view transformation
    painter.setWindow(QRect(-50, -50, 100, 100));
    int radius = qMin(rect().height(), rect().width()) / 2;
    if (radius > margin) radius -= margin;
    int cx = rect().center().x();
    int cy = rect().center().y();
    painter.setViewport(cx-radius,cy-radius,
                        radius*2, radius*2);

    // draw face
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(Qt::white);

    painter.drawEllipse(-50, -50, 100, 100);

    // draw needle
    painter.rotate(m_direction * -1.0); // inverse because y-axis is down
    painter.setPen(QPen(Qt::red, 4));
    painter.drawLine(0, 0, 0, 48);
    painter.setPen(QPen(Qt::blue, 4));
    painter.drawLine(0, 0, 0, -48);
    painter.setPen(QPen(Qt::black, 8));
    painter.drawPoint(0, 0);
}
