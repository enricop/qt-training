/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef OBJECTBROWSERMODEL_H
#define OBJECTBROWSERMODEL_H

#include <QAbstractTableModel>

class ObjectBrowserModel :public QAbstractItemModel
{
public:
    int columnCount ( const QModelIndex& parent = QModelIndex() ) const;
    int rowCount ( const QModelIndex& parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex& index, int role = Qt::DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation, int role = Qt::DisplayRole ) const;
    QModelIndex index ( int row, int column, const QModelIndex& parent = QModelIndex() ) const;
    QModelIndex parent ( const QModelIndex & index ) const;

protected:
    QList<QObject*> children( QObject* parent ) const;
    QString label( const QObject* widget, int column ) const;
    QObject* qobjectFromModelIndex( const QModelIndex& ) const;

private:
    QWidget* _widget; // TODO throw out!
};

#endif /* OBJECTBROWSERMODEL_H */

