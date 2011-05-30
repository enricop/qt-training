/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "pipeline.h"

Pipeline::Pipeline(QObject *parent)
    : QObject(parent)
{
}

void Pipeline::clear()
{
    queue.clear();
}

QByteArray Pipeline::dequeue()
{
    return queue.dequeue();
}

void Pipeline::enqueue(const QByteArray &data)
{
    queue.enqueue(data);
    emit readyRead();
}

bool Pipeline::isEmpty() const
{
    return queue.isEmpty();
}
