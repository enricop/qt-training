/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "bookstore.h"
#include "bookmodel.h"
#include "../tabletolistmodel.h"

#include <QtQuick>
#include <QtSql>

BookStore::BookStore( QObject *parent ) : QObject( parent )
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "../bookstore.db" );
    if ( !db.open() )
        reportError( "Error When opening database", db.lastError() );

    // Set up the models
    m_authorsModel = new QSqlTableModel( this );
    // Step 1: setup authors model

    m_bookModel = new BookModel( this );

    // Step 2: setup proxies
    m_authorsModelProxy = new TableToListModel( this );

    m_bookModelProxy = new TableToListModel( this );
}

void BookStore::reportError( const QString& msg, const QSqlError& err )
{
    qDebug() <<
        QString("%1\nDriver Message: %2\nDatabase Message %3")
        .arg(msg)
        .arg(err.driverText())
        .arg(err.databaseText());
    qApp->exit(-1);
}

QObject *BookStore::authorsModel() const
{
    return m_authorsModelProxy;
}

QObject *BookStore::bookModel() const
{
    return m_bookModelProxy;
}

void BookStore::authorChanged( int row )
{
    int authorId = m_authorsModel->data( m_authorsModel->index( row, 0, QModelIndex() ) ).toInt();
    m_bookModel->showAuthor( authorId );
}
