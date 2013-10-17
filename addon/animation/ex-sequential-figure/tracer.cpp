#include <QtGui>
#include <QtSvg>
#include "tracer.h"

#define STEPS 6

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
    lastAnimation = 0;
    alphaValue = 0;
}

Tracer::~Tracer()
{
    painter->end();
    delete painter;
    delete generator;
}

void Tracer::drawLast()
{
    QPropertyAnimation *animation = static_cast<QPropertyAnimation *>(sender());

    animation->setCurrentTime(animation->duration());
}

void Tracer::drawPath(const QVariant &value)
{
    QAbstractAnimation *animation = static_cast<QAbstractAnimation *>(sender());

    if (lastAnimation != animation)
        currentSnapshot = 0;

    if (int(qreal(animation->currentTime())/animation->duration() * STEPS) >= currentSnapshot) {
        QPixmap pixmap = pixmaps[animation];
        painter->drawPixmap(value.toPoint(), pixmap);

        lastAnimation = animation;
        currentSnapshot++;
        alphaValue++;
    }
}

void Tracer::setPixmap(QAbstractAnimation *animation, const QPixmap &pixmap)
{
    pixmaps[animation] = pixmap;
}
