/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtSql>
#include "bookmodel.h"
#include "bookstore.h"

BookModel::BookModel( QObject* parent )
    : QSqlQueryModel( parent )
{
}

void BookModel::showAuthor( int authorId )
{
    // Step 3: Implement method for loading a given author.
    qDebug("Author Changed: %d", authorId);
}

// Step 5: Allow editing by implementing setData and flags.

bool BookModel::removeRows( int row, int count, const QModelIndex& parent  )
{
    for ( int i=0; i< count; ++i ) {
        QModelIndex primaryKeyIndex = index( row, 0 , parent );
        int primaryKey = data( primaryKeyIndex ).toInt();

        QSqlQuery query;
        query.prepare( QString( "DELETE FROM book where id = :id" ) );
        query.bindValue( ":id", primaryKey );
        bool ok = query.exec();
        if ( !ok ) {
            BookStore::reportError( "Error running DELETE command", query.lastError() );
            return false;
        }
        refresh();
    }
    return true;
}

bool BookModel::insertRows( int /*row*/, int count, const QModelIndex &/*parent*/ )
{
    for ( int i=0; i < count; ++i ) {
        QSqlQuery query;
        query.prepare( QString( "INSERT INTO book (authorId, price) VALUES (:id, 1)" ) );
        query.bindValue( ":id", m_authorId );
        bool ok = query.exec();
        if ( !ok ) {
            BookStore::reportError( "Error running INSERT command", query.lastError() );
            return false;
        }
        refresh();
    }
    return true;

}

void  BookModel::refresh()
{
    showAuthor( m_authorId );
}
