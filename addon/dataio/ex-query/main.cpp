/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtQuick>
#include <QtSql>
#include <QStandardItemModel>

class BookModel : public QStandardItemModel
{
public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        AuthorRole,
        PriceRole,
        NotesRole
    };

    BookModel() : QStandardItemModel()
    {
        setSortRole(AuthorRole);
    }

    QHash<int, QByteArray> roleNames() const
    {
        QHash<int, QByteArray> mapping = QStandardItemModel::roleNames();

        mapping[TitleRole] = "title";
        mapping[AuthorRole] = "author";
        mapping[PriceRole] = "price";
        mapping[NotesRole] = "notes";

        return mapping;
    }

    void addBook(const QString &title, const QString &author, const QString &price, const QString &notes)
    {
        QStandardItem *item = new QStandardItem;
        item->setData(title, TitleRole);
        item->setData(author, AuthorRole);
        item->setData(price, PriceRole);
        item->setData(notes, NotesRole);

        appendRow(item);
    }
};


void reportError( const QString& msg, const QSqlError& err )
{
    qDebug() <<
        QString("%1\nDriver Message: %2\nDatabase Message %3")
        .arg(msg)
        .arg(err.driverText())
        .arg(err.databaseText());
  qApp->exit(-1);
}


int main( int argc, char** argv )
{
  QGuiApplication app(argc, argv);

  // Connect to the database
  QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
  db.setDatabaseName("../bookstore.db");
  if ( !db.open() ) {
    reportError( "Error When opening database", db.lastError() );
  }
  
  // Setup the data model
  BookModel model;

  // Query the database
  QSqlQuery authorQuery("SELECT id, firstname, surname FROM author");
  if ( ! authorQuery.isActive() )
    reportError("Eror when running Query", authorQuery.lastError());

  while ( authorQuery.next() ) {
    const QString author = authorQuery.value(1).toString() + " " + authorQuery.value(2).toString();

    // Query all the books of the author.
    QSqlQuery bookQuery( "SELECT title, price, notes FROM book WHERE authorid = " + authorQuery.value(0).toString());

    if ( ! bookQuery.isActive() )
      reportError("Eror when running Query",bookQuery.lastError());

    while ( bookQuery.next() ) {
        model.addBook(bookQuery.value(0).toString(), author, bookQuery.value(1).toString(), bookQuery.value(2).toString() );
    }
  }

  QQuickView view;
  view.engine()->rootContext()->setContextProperty("_model", &model);
  view.setSource(QUrl("main.qml"));
  view.show();


  return app.exec();
}
