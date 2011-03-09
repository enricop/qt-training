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


QObject* ObjectBrowserModel::mapModelIndex2QObject( const QModelIndex& index ) const
{
    if ( index.isValid() )
        return children( reinterpret_cast<QObject*>( index.internalPointer() ) )[index.row()];

    return 0; // This is the root.
}

int ObjectBrowserModel::columnCount( const QModelIndex& /* parent */ ) const
{
    return 3;
}

int ObjectBrowserModel::rowCount( const QModelIndex& parent ) const
{
    return children(mapModelIndex2QObject(parent)).count();
}

QVariant ObjectBrowserModel::data( const QModelIndex& index, int role ) const
{
    if ( !index.isValid() || role != Qt::DisplayRole )
        return QVariant();

    QObject* obj = mapModelIndex2QObject(index);
    return label( obj, index.column() );
}

QList<QObject*> ObjectBrowserModel::children( QObject* parent ) const
{
    QList<QObject*> result;
    if ( parent == 0 ) {
        QList<QWidget*> widgets = QApplication::topLevelWidgets();

        foreach ( QWidget* widget, widgets )
            if ( widget->isVisible() && widget->windowType() != Qt::Desktop)
                result.append( widget );
    }
    else
        result = parent->children();

    qSort( result );
    return result;
}

QVariant ObjectBrowserModel::headerData( const int section, const Qt::Orientation orient , const int role ) const
{
    if ( orient != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractItemModel::headerData( section, orient, role );

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
QModelIndex ObjectBrowserModel::index( int row, int column, const QModelIndex & parent ) const
{
    return createIndex( row, column, mapModelIndex2QObject(parent) );
}

QModelIndex ObjectBrowserModel::parent( const QModelIndex & index ) const
{
    QObject* obj = mapModelIndex2QObject(index);
    QObject* parent = obj->parent();
    if ( parent == 0 )
        return QModelIndex();

    QObject* grandParent = parent->parent();
    int row = children( grandParent ).indexOf( parent );
    return createIndex( row, 0, grandParent );
}

