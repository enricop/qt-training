/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ANIMATIONQUEUE_H
#define ANIMATIONQUEUE_H

#include <QObject>
#include <QTransform>
#include <QTimeLine>
class CoordinateSystem;
class TransformationItem;

/** Applies a list of TransformationItem objects
    in sequence to an image.
*/
class AnimationQueue : public QObject
{
    Q_OBJECT
public:
    AnimationQueue(CoordinateSystem *graphicsObject, QObject* parent=0);
    void add(TransformationItem* i);
    void setItem(CoordinateSystem* a) {
        m_before = a;
    }
protected slots:
    void applyGradual(TransformationItem*);
    void advance(qreal);
    void finishAnimation();
signals:
    void operationFinished();
    void animating(TransformationItem*);
private:
    QTimeLine m_timeLine;
    CoordinateSystem *m_before, *m_after;
    QList<TransformationItem*> m_queue;
    TransformationItem* m_currentOperation;

};

#endif // ANIMATIONQUEUE_H
