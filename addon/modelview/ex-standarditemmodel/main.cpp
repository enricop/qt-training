/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

#include "cityengine.h"


// !!! Typedefs for Qt classes !!!
typedef QStandardItemModel ItemModel;
typedef QStandardItem Item;

class ViewContainer : public QMainWindow
{
    Q_OBJECT
public:
    ViewContainer(QWidget *parent=0) : QMainWindow(parent) {

        m_engine = new CityEngine(this);

        QSplitter *container = new QSplitter(Qt::Horizontal);

        // Uncomment on of the create model helper functions

        m_model = createListModel();
//        m_model = createTableModel();

        QListView* list = new QListView;
        list->setModel( m_model );
        connect(list, SIGNAL(clicked(QModelIndex)), this, SLOT(onClicked(QModelIndex)));
        container->addWidget(list);

        QTableView* table = new QTableView;
        table->setModel( m_model );
        connect(table, SIGNAL(clicked(QModelIndex)), this, SLOT(onClicked(QModelIndex)));
        container->addWidget(table);

        QTreeView* tree = new QTreeView;
        tree->setModel( m_model );
        connect(tree, SIGNAL(clicked(QModelIndex)), this, SLOT(onClicked(QModelIndex)));
        container->addWidget(tree);

        setCentralWidget(container);
    }

private slots:
    void onClicked(const QModelIndex &index) {
        Item *item = m_model->itemFromIndex(index);
        qDebug() << "item clicked " << item->text();

        qDebug() << "    text on index" << index.data(Qt::DisplayRole).toString();
        qDebug() << "    position = " << index.row() << " " << index.column();
    }

private:
    ItemModel *createListModel() {
        ItemModel *model = new ItemModel(this);

        QStringList cities = m_engine->cities();

        foreach(const QString &city, cities) {
            model->appendRow(new Item(city));
        }

        return model;
    }

    ItemModel *createTableModel() {
        ItemModel *model = new ItemModel(this);

        QStringList cities = m_engine->cities();

        foreach(const QString &city, cities) {

            QString country = m_engine->country(city);
            QIcon flag = m_engine->flag(country);
            QString population = QString::number(m_engine->population(city));
            QString area = QString::number(m_engine->area(city));

            QList<Item*> items;
            items << new Item(city) << new Item(flag, country);
            items << new Item(population) << new Item(area);

            model->appendRow(items);
        }

        return model;
    }
private:
    ItemModel *m_model;
    CityEngine *m_engine;

};

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    ViewContainer *container = new ViewContainer();

    container->show();

    return app.exec();
}

#include "main.moc"

