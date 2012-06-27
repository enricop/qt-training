/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QtQuick>
#include "bookstore.h"

int main( int argc, char** argv ) {
    QGuiApplication app( argc, argv );
    BookStore* bookStore = new BookStore;

    QQuickView view;
    view.engine()->rootContext()->setContextProperty( "_bookStore", bookStore );
    view.setSource(QUrl("main.qml"));
    view.show();

    return app.exec();
}
