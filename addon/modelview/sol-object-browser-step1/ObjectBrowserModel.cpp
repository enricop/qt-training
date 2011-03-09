/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "ObjectBrowserModel.h"
#include <QApplication>
#include <QWidget>

ObjectBrowserModel::ObjectBrowserModel( QWidget* widget )
    :_widget(widget)
{
}

int ObjectBrowserModel::columnCount( const QModelIndex& /* parent */ ) const
{
    return 3;
}

int ObjectBrowserModel::rowCount( const QModelIndex& /*parent */ ) const
{
    return children(_widget).count();
}

QVariant ObjectBrowserModel::data( const QModelIndex& index, int role ) const
{
    if ( !index.isValid() || role != Qt::DisplayRole )
        return QVariant();

    QObject* obj = children(_widget)[index.row()];
    return label( obj, index.column() );
}

QList<QObject*> ObjectBrowserModel::children( QObject* parent ) const
{
    QList<QObject*> result = parent->children();
    return result;
}

QVariant ObjectBrowserModel::headerData( const int section, const Qt::Orientation orient , const int role ) const
{
    if ( orient != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractTableModel::headerData( section, orient, role );

    switch ( section ) {
    case 0: return "Class Name";
    case 1: return "Object Name";
    case 2: return "Address";
    }

    return QVariant();
}

QString ObjectBrowserModel::label( const QObject* obj, const int column ) const
{
    switch ( column ) {
    case 0: return obj->metaObject()->className();
    case 1: return obj->objectName();
    case 2:
    {
        QString str;
        str.sprintf("%p", obj);
        return str ;
    }

    default:
        return QString();
    }
}

