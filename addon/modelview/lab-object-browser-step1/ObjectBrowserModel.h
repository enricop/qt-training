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

class ObjectBrowserModel :public QAbstractTableModel
{
public:
    ObjectBrowserModel( QWidget* widget );
    int columnCount ( const QModelIndex& parent = QModelIndex() ) const;
    int rowCount ( const QModelIndex& parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex& index, int role = Qt::DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation, int role = Qt::DisplayRole ) const;

protected:
    QList<QObject*> children( QObject* parent ) const;
    QString label( const QObject* widget, int column ) const;

private:
    QWidget* _widget;
};

#endif /* OBJECTBROWSERMODEL_H */

