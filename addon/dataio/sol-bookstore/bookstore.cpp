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
#include "bookstore.h"
#include "bookmodel.h"

BookStore::BookStore()
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL3" );
    db.setDatabaseName("bookstore");
    if ( !db.open() )
        reportError( "Error When opening database", db.lastError() );

    // Set up the models
    m_authorsModel = new QSqlTableModel( this );
    m_authorsModel->setTable( "author" );
    m_authorsModel->select();
    m_authorsModel->setHeaderData( 1, Qt::Horizontal, "First Name" );
    m_authorsModel->setHeaderData( 2, Qt::Horizontal, "Sur Name" );

    m_bookModel = new BookModel( this );

    // The GUI
    QSplitter* splitter = new QSplitter( Qt::Vertical, this );
    m_authorView = new QTableView( splitter );
    m_authorView->setModel( m_authorsModel );
    m_authorView->setColumnHidden( 0, true ); // Don't show ID column
    m_authorView->verticalHeader()->hide();

    m_bookView = new QTableView( splitter );
    m_bookView->setModel( m_bookModel );
    m_bookView->verticalHeader()->hide();

    connect( m_authorView->selectionModel(), SIGNAL( currentChanged( const QModelIndex&, const QModelIndex& ) ),
             this, SLOT( authorChanged( const QModelIndex& ) ) );

    m_authorView->installEventFilter( this );
    m_bookView->installEventFilter( this );

    // The Layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget( splitter );
    setLayout( layout );

    // Select the first item in the author model.
    m_authorView->selectionModel()->setCurrentIndex( m_authorsModel->index( 0, 1, QModelIndex() ), QItemSelectionModel::Select );
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

void BookStore::authorChanged( const QModelIndex& index )
{
    int authorId = m_authorsModel->data( m_authorsModel->index( index.row(), 0, QModelIndex() ) ).toInt();
    m_bookModel->showAuthor( authorId );
    m_bookView->setColumnHidden( 0, true ); // Don't show the ID column
}

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
