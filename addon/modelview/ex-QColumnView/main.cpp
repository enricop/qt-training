/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QColumnView* view = new QColumnView;
    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath( QDir::root().path() );
    view->setModel( model );
    view->resize( 800, 600 );
    view->show();

    return app.exec();
}
