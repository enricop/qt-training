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
class QAbstractItemModel;

namespace Ui { class BookStore; }

class BookStore :public QWidget
{
    Q_OBJECT
public:
    BookStore( QAbstractItemModel* model );

private:
    Ui::BookStore* _ui;
};

#endif /* BOOKSTORE_H */

