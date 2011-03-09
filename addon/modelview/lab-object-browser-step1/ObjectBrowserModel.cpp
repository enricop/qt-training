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

QList<QObject*> ObjectBrowserModel::children( QObject* parent ) const
{
    // TODO: Return the list of all the children of 'parent'
    return QList<QObject*>();
}

QString ObjectBrowserModel::label( const QObject* obj, const int column ) const
{
    // Return the conten for a given column
    switch ( column ) {
    case 0: // TODO: return class name
    case 1: // TODO: return object name
    case 2: // TODO: return pointer address
        return "Hello World";
    }
    return QString();
}

int ObjectBrowserModel::columnCount( const QModelIndex& parent ) const
{
    // TODO: implement
    return 0;
}

int ObjectBrowserModel::rowCount( const QModelIndex& parent ) const
{
    // TODO: implement
    // Hint: Your children method above might be utterly useful now
    return 0;
}

QVariant ObjectBrowserModel::data( const QModelIndex& index, int role ) const
{
    // TODO: implement
    // Hint: Your label method might come in handy now.
    return QVariant();
}

QVariant ObjectBrowserModel::headerData( const int section, const Qt::Orientation orient , const int role ) const
{
    // TODO: implement
    return QAbstractTableModel::headerData( section, orient, role );
}

