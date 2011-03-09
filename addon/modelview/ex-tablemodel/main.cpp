/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

class CellModel : public QAbstractTableModel
{
public:
    explicit CellModel(QObject *parent=0) : QAbstractTableModel(parent) {}

    int columnCount ( const QModelIndex & parent = QModelIndex() ) const {
        if(parent.isValid()) {
            return 0;
        }
        return 4;
    }
    int	rowCount ( const QModelIndex & parent = QModelIndex() ) const {
        if(parent.isValid()) {
            return 0;
        }
        return 3;
    }
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const {
        if(!index.isValid()) {
            return QVariant();
        }
        switch(role) {
        case Qt::DisplayRole:
            return QString("Cell(%1,%2)").arg(index.row()).arg(index.column());
        }
        return QVariant();
    }

    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const {
        if(role != Qt::DisplayRole) {
            return QVariant();
        }
        switch(orientation) {
        case Qt::Horizontal:
            return QString("Row %1").arg(section);
        case Qt::Vertical:
            return QString("Column %1").arg(section);
        }
        return QVariant();
    }
};

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    CellModel *model = new CellModel(QCoreApplication::instance());

    QListView* list = new QListView;
    list->setModel( model );
    list->setWindowTitle( "QListView" );
    list->show();

    QTreeView* tree = new QTreeView;
    tree->setModel( model );
    tree->setWindowTitle( "QTreeView" );
    tree->show();

    QTableView* table = new QTableView;
    table->setModel( model );
    table->setWindowTitle( "QTableView" );
    table->show();

    return app.exec();
}
