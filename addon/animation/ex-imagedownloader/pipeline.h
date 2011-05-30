/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PIPELINE_H
#define PIPELINE_H

#include <QObject>
#include <QQueue>

class Pipeline : public QObject
{
    Q_OBJECT

public:
    Pipeline(QObject *parent = 0);
    void clear();
    QByteArray dequeue();
    void enqueue(const QByteArray &data);
    bool isEmpty() const;

signals:
    void readyRead();

private:
    QQueue<QByteArray> queue;
};

#endif
