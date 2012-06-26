/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtSql>
#include <QtQuick>

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


class EditableQueryModel :public QSqlQueryModel
{
public:
    EditableQueryModel()
    {
        refresh();
        setHeaderData( 0, Qt::Horizontal, "First Name" );
        setHeaderData( 1, Qt::Horizontal, "Sur Name" );
        setHeaderData( 2, Qt::Horizontal, "Title" );
        setHeaderData( 3, Qt::Horizontal, "Price" );
        setHeaderData( 4, Qt::Horizontal, "Notes" );
    }

    Qt::ItemFlags flags( const QModelIndex& index ) const
    {
        Qt::ItemFlags flags = QSqlQueryModel::flags(index);
        if (index.column() >= 2 )
            flags |= Qt::ItemIsEditable;
        return flags;
    }

    bool setData(const QModelIndex &index, const QVariant& value, int /* role */)
    {
        Q_ASSERT(index.column()>= 2);

        QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 5 );
        int id = data(primaryKeyIndex).toInt();

        QString field;
        switch ( index.column() ) {
        case 2: field = "title"; break;
        case 3: field = "price"; break;
        case 4: field = "notes"; break;
        }

        QSqlQuery query;
        query.prepare( QString("update book set %1 = ? where id  = ?" ).arg( field ) );
        query.addBindValue( value );
        query.addBindValue( id );
        bool ok = query.exec();
        if ( !ok )
            reportError("Error running update query", query.lastError() );
        refresh();
        return ok;
    }

    void refresh()
    {
        setQuery( "SELECT a.firstname, a.surname, b.title, b.price, b.notes, b.id  FROM author a, book b WHERE a.id = b.authorid" );
    }
};

int main( int argc, char** argv ) {
    QGuiApplication app( argc, argv );

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("../bookstore.db");
    if ( !db.open() )
        reportError( "Error When opening database", db.lastError() );

    EditableQueryModel* model = new EditableQueryModel;

    TableToListModel proxy;
    proxy.setTableModel(model);

    proxy.addColumnMapping(0, "firstName");
    proxy.addColumnMapping(1, "lastName");
    proxy.addColumnMapping(2, "title");
    proxy.addColumnMapping(3, "price");
    proxy.addColumnMapping(4, "notes");

    QQuickView view;

    view.engine()->rootContext()->setContextProperty("_model", &proxy);
    view.setSource(QUrl("main.qml"));

    view.show();

    return app.exec();
}
