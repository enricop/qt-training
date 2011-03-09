/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DNDMODEL_H
#define DNDMODEL_H

#include <QtCore>

#include "insertremovemodel.h"

class DndModel : public InsertRemoveModel
{
public:
    explicit DndModel(QObject *parent = 0);
    ~DndModel();

    Qt::ItemFlags flags(const QModelIndex &index) const;
    Qt::DropActions supportedDragActions() const;
    Qt::DropActions supportedDropActions() const;
    QStringList mimeTypes() const;
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                      int row, int column, const QModelIndex &parent);

    bool removeRows(int row, int count, const QModelIndex &parent);
//    bool insertRows(int row, int count, const QModelIndex &parent);
};

#endif // DNDMODEL_H
