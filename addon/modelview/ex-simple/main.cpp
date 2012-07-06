/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>
#include <QSplitter>
#include <QApplication>

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QSplitter* splitter = new QSplitter;

    QTreeView* tree = new QTreeView( splitter );
    QListView* list = new QListView( splitter );

    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath( QDir::root().path() );

    tree->setModel( model );
    list->setModel( model );

    list->setRootIndex( model->index( "." ) );

    splitter->show();

    return app.exec();
}
