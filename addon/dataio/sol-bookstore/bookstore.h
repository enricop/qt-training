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

#include <QWidget>
class QTableView;
class BookModel;
class QModelIndex;
class QSqlTableModel;
class QSqlError;

class BookStore :public QWidget
{
    Q_OBJECT
public:
    BookStore();
    static void reportError( const QString& msg, const QSqlError& err );

protected:
    virtual bool eventFilter( QObject* watched, QEvent* event );

protected slots:
    void authorChanged( const QModelIndex& );


private:
    QSqlTableModel* m_authorsModel;
    BookModel* m_bookModel;
    QTableView* m_authorView;
    QTableView* m_bookView;
};

#endif /* BOOKSTORE_H */

