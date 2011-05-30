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

#include <QObject>
#include <QPoint>
class QPainter;
class QSvgGenerator;

class Tracer : public QObject
{
    Q_OBJECT

public:
    Tracer(QWidget *parent, const QString &path);
    ~Tracer();

public slots:
    void drawPath(const QVariant &value);

private:
    QPainter *painter;
    QSvgGenerator *generator;
    int currentSnapshot;
    QPoint lastPoint;
};

#endif
