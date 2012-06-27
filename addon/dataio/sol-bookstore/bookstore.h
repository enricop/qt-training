/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QObject>

class BookModel;
class TableToListModel;
class QModelIndex;
class QSqlTableModel;
class QSqlError;

class BookStore :public QObject
{
    Q_OBJECT
    Q_PROPERTY( QObject* authorsModel READ authorsModel CONSTANT )
    Q_PROPERTY( QObject* bookModel READ bookModel CONSTANT )

public:
    explicit BookStore( QObject *parent = 0 );
    static void reportError( const QString& msg, const QSqlError& err );

    QObject *authorsModel() const;
    QObject *bookModel() const;

    Q_INVOKABLE void authorChanged( int row );

    Q_INVOKABLE void addAuthor();
    Q_INVOKABLE void removeAuthor( int row );

    Q_INVOKABLE void addBook();
    Q_INVOKABLE void removeBook( int row );

private:
    QSqlTableModel* m_authorsModel;
    BookModel* m_bookModel;

    TableToListModel *m_authorsModelProxy;
    TableToListModel *m_bookModelProxy;
};

#endif /* BOOKSTORE_H */

