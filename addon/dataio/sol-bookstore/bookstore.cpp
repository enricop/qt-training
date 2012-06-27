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

#if 0
bool BookStore::eventFilter( QObject* watched, QEvent* event )
{
    if ( event->type() == QEvent::ContextMenu ) {
        QModelIndex index;
        QAbstractItemModel* model;
        QString item;
        if ( watched == m_authorView ) {
            index = m_authorView->indexAt( m_authorView->viewport()->mapFromGlobal( QCursor::pos() ) );
            QString firstName = m_authorsModel->data( m_authorsModel->index( index.row(), 1 ) ).toString();
            QString surName =  m_authorsModel->data( m_authorsModel->index( index.row(), 2 ) ).toString();
            item = QString( "%1 %2" ).arg( firstName ).arg( surName );
            model = m_authorsModel;
        }
        else if ( watched == m_bookView ) {
            index = m_bookView->indexAt( m_bookView->viewport()->mapFromGlobal( QCursor::pos() ) );
            item = m_bookModel->data( m_bookModel->index( index.row(), 1 ) ).toString();
            model = m_bookModel;
        }
        else
            return false;

        QMenu* menu = new QMenu;
        QAction* add = menu->addAction( "Add New Item" );
        QAction* del = menu->addAction( QString( "Delete %1" ).arg( item ) );
        del->setEnabled( index.isValid() );

        QAction* action = menu->exec( QCursor::pos() );

        if ( action == add ) {
            if ( index.isValid() )
                model->insertRow( index.row(), index.parent() );
            else
                model->insertRow( model->rowCount(), QModelIndex() );
        }
        else if ( action == del ) {
            model->removeRow( index.row(), index.parent() );
        }

        return true;
    }
    return false;
}
#endif
