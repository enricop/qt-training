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

#define STEPS 8

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
        QPixmap alpha = QPixmap(64, 64);
        qreal v = 1.0/(STEPS + 1) + qreal(animation->currentTime())/animation->duration() * (qreal(STEPS)/(STEPS + 1));
        v = v * 255;
        alpha.fill(qRgb(v, v, v));
        QRect rect = value.toRect();
        QPixmap pixmap(":icons/icon.png");
        pixmap.setAlphaChannel(alpha);
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
