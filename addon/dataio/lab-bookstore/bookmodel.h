/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QSqlQueryModel>

class BookModel :public QSqlQueryModel
{
public:
    BookModel( QObject* parent );
    void showAuthor( int authorId );
    virtual bool removeRows( int row, int count, const QModelIndex& parent = QModelIndex() );
    virtual bool insertRows( int row, int count, const QModelIndex & parent = QModelIndex() );

protected:
    void refresh();
private:
    int m_authorId;
};

#endif /* BOOKMODEL_H */

