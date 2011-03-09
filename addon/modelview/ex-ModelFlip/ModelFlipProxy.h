/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MODELFLIPPROXY_H
#define MODELFLIPPROXY_H

#include <QAbstractProxyModel>

class ModelFlipProxy : public QAbstractProxyModel
{
    Q_OBJECT
public:
    explicit ModelFlipProxy ( QObject* parent = 0 );
    ~ModelFlipProxy ();

    QModelIndex mapFromSource ( const QModelIndex & sourceIndex ) const;
    QModelIndex mapToSource ( const QModelIndex & proxyIndex ) const;

    QModelIndex index(int, int, const QModelIndex&) const;
    QModelIndex parent(const QModelIndex&) const;
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex&, int) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
};

#endif
