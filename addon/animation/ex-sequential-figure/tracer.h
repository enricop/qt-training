/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TRACER_H
#define TRACER_H

#include <QHash>
#include <QObject>
#include <QPixmap>
#include <QPoint>
class QAbstractAnimation;
class QPainter;
class QSvgGenerator;

class Tracer : public QObject
{
    Q_OBJECT

public:
    Tracer(QWidget *parent, const QString &path);
    ~Tracer();
    void setPixmap(QAbstractAnimation *animation, const QPixmap &pixmap);

public slots:
    void drawLast();
    void drawPath(const QVariant &value);

private:
    int alphaValue;
    int currentSnapshot;
    QAbstractAnimation *lastAnimation;
    QHash<QAbstractAnimation *, QPixmap> pixmaps;
    QPainter *painter;
    QSvgGenerator *generator;
};

#endif