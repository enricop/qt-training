/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtQuick>
#include <QtSql>

#include "../tabletolistmodel.h"

void reportError( const QString& msg, const QSqlError& err )
{
    qDebug() <<
        QString("%1\nDriver Message: %2\nDatabase Message %3")
        .arg(msg)
        .arg(err.driverText())
        .arg(err.databaseText());
    qApp->exit(-1);
}

int main( int argc, char** argv ) {
    QGuiApplication app( argc, argv );

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("../bookstore.db");
    if ( !db.open() )
        reportError( "Error When opening database", db.lastError() );

    QSqlRelationalTableModel* model = new QSqlRelationalTableModel;
    model->setTable("book");
    model->setRelation( 3, QSqlRelation( "author", "id", "surname" ) );
    model->select();

    TableToListModel proxy;
    proxy.setTableModel(model);

    proxy.addColumnMapping(1, "title");
    proxy.addColumnMapping(2, "price");
    proxy.addColumnMapping(3, "lastName");

    QQuickView view;

    view.engine()->rootContext()->setContextProperty("_model", &proxy);
    view.setSource(QUrl("main.qml"));

    view.show();

    return app.exec();
}
