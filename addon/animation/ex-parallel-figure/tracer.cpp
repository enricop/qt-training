/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

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
    lastSnapshot = 0;
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

    QPixmap pixmap = pixmaps[animation];
    painter->drawPixmap(animation->endValue().toPoint(), pixmap);
}

void Tracer::drawPath(const QVariant &value)
{
    QPropertyAnimation *animation = static_cast<QPropertyAnimation *>(sender());
    
    if (!lastAnimation)
        lastAnimation = animation;
    else if (lastAnimation == animation && currentSnapshot == lastSnapshot) {
        currentSnapshot++;
        alphaValue++;
    }

    if ((qreal(animation->currentTime())/animation->duration() * STEPS) >= currentSnapshot) {
        QPixmap pixmap = pixmaps[animation];
        QPixmap alpha = QPixmap(pixmap.size());
        qreal v = 1.0/(STEPS + 1) + (qreal(alphaValue)/(STEPS + 1));
        v = v * 255;
        alpha.fill(qRgb(v, v, v));
        pixmap.setAlphaChannel(alpha);
        painter->drawPixmap(value.toPoint(), pixmap);

        lastSnapshot = currentSnapshot;
    }
}

void Tracer::setPixmap(QPropertyAnimation *animation, const QPixmap &pixmap)
{
    pixmaps[animation] = pixmap;
}
