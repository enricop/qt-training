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
    m_authorsModel->setTable( "author" );
    m_authorsModel->select();

    m_bookModel = new BookModel( this );

    m_authorsModelProxy = new TableToListModel( this );
    m_authorsModelProxy->setTableModel( m_authorsModel );
    m_authorsModelProxy->addColumnMapping(1, "firstName");
    m_authorsModelProxy->addColumnMapping(2, "lastName");

    m_bookModelProxy = new TableToListModel( this );
    m_bookModelProxy->setTableModel( m_bookModel );
    m_bookModelProxy->addColumnMapping(1, "title");
    m_bookModelProxy->addColumnMapping(2, "price");
    m_bookModelProxy->addColumnMapping(3, "notes");
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

void BookStore::addAuthor()
{
    m_authorsModel->insertRow( m_authorsModel->rowCount(), QModelIndex() );
}

void BookStore::removeAuthor( int row )
{
    m_authorsModel->removeRow( row, QModelIndex() );
}

void BookStore::addBook()
{
    m_bookModel->insertRow( m_bookModel->rowCount(), QModelIndex() );
}

void BookStore::removeBook( int row )
{
    m_bookModel->removeRow( row, QModelIndex() );
}
