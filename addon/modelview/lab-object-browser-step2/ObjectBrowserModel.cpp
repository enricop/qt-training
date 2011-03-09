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

QObject* ObjectBrowserModel::qobjectFromModelIndex( const QModelIndex& index ) const
{
    Q_UNUSED( index );
    // TODO: Map from model index to the associated widget.
    // You did start out by writing down exactly what goes into the internal-pointer, right?
    // If not, please do read the object assignment yet another time!
    return 0;
}

int ObjectBrowserModel::columnCount( const QModelIndex& /* parent */ ) const
{
    return 3;
}

int ObjectBrowserModel::rowCount( const QModelIndex& /*parent */ ) const
{
    // TODO: Implement.
    return 0;
}

QVariant ObjectBrowserModel::data( const QModelIndex& index, int role ) const
{
    // TODO: implement
    if ( !index.isValid() || role != Qt::DisplayRole )
        return QVariant();

    QObject* obj = 0; // TODO: Now how do you get to the object for the index?
    return label( obj, index.column() );
}

QList<QObject*> ObjectBrowserModel::children( QObject* parent ) const
{
    // Notice this function has been updated now. It return the toplevel widgets when parent is 0
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
    Q_UNUSED( row );
    Q_UNUSED( column );
    Q_UNUSED( parent );
    // TODO implement. Hint: use QAbstractItemModel::createIndex.
    return QModelIndex();
}

QModelIndex ObjectBrowserModel::parent( const QModelIndex & index ) const
{
    QObject* obj = qobjectFromModelIndex(index);
    QObject* parent = obj ? obj->parent() : 0;
    if ( parent == 0 )
        return QModelIndex();

    QObject* grandParent = parent->parent();
    int row = children( grandParent ).indexOf( parent );
    return createIndex( row, 0, parent );
}

