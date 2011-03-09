/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include "ObjectBrowserModel.h"
#include <QTableView>
#include <QDialog>
#include "ui_test.h"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QDialog* dialog = new QDialog;
    Ui::Test* ui = new Ui::Test;
    ui->setupUi( dialog );
    dialog->show();

    ObjectBrowserModel* model = new ObjectBrowserModel(dialog);
    QTableView* view = new QTableView;
    view->setModel( model );
    view->resize( 400, 600 );
    view->show();

    return app.exec();
}
