/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include "mainwindow.h"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    MainWindow mw;
    mw.show();

    return app.exec();
}
