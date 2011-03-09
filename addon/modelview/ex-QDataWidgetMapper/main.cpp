/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "BookStore.h"
#include <QtGui>

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    struct Data
    {
        const char* title;
        const char* author;
        double price;
    };

    Data data[] = { {"Practical Qt", "Kalle Mathias Dalheimer",  45.00},
                    {"Programming with Qt", "Kalle Mathias Dalheimer",  39.95},
                    {"C++ GUI Programming with Qt 4", "Jasmin Blanchette", 59.95 },
                    {"The Art of Building Qt Applications", "Daniel Molkentin",  54.95},
                    {"An Introduction to Design Patterns in C++ with Qt 4", "Alan Ezust", 54.95 }
    };


    // Just a simple model.
    const unsigned int rows = sizeof(data) / sizeof(Data);
    QStandardItemModel* model = new QStandardItemModel( rows, 3 );
    for ( unsigned int row = 0; row < rows; ++row ) {
        model->setData( model->index( row, 0 ), data[row].title );
        model->setData( model->index( row, 1 ), data[row].author );
        model->setData( model->index( row, 2 ), data[row].price );
    }

    // A simple view
    QTableView* tableView = new QTableView;
    tableView->setModel( model );
    tableView->show();

    // QDataWidetMapper
    BookStore* bookStore = new BookStore( model );
    bookStore->show();

    return app.exec();
}
