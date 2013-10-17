#include <QtGui>
#include <QtSvg>
#include "tracer.h"

#define STEPS 10

Tracer::Tracer(QWidget *parent, const QString &path)
    : QObject(parent)
{
    generator = new QSvgGenerator();
    generator->setSize(parent->size());
    generator->setViewBox(parent->rect());
    generator->setFileName(path);
    painter = new QPainter();
    painter->begin(generator);

    currentSnapshot = 0;
    lastPoint = QPoint(-1, -1);
}

Tracer::~Tracer()
{
    painter->end();
    delete painter;
    delete generator;
}

void Tracer::drawPath(const QVariant &value)
{
    QAbstractAnimation *animation = static_cast<QAbstractAnimation *>(sender());
    if ((qreal(animation->currentTime())/animation->duration() * STEPS) >= currentSnapshot) {
        QRect rect = value.toRect();
        QPixmap pixmap(":icons/icon.png");
        painter->drawPixmap(rect.topLeft(), pixmap);

        painter->setPen(QPen(Qt::red, 2));
        QPoint newPoint = rect.center() + QPoint(0, 48);
        painter->drawLine(newPoint + QPoint(0, -8), newPoint + QPoint(0, 8));
        if (lastPoint.x() >= 0)
            painter->drawLine(lastPoint, newPoint);
        
        lastPoint = newPoint;
        currentSnapshot++;
    }
}
