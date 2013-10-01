#include <QtWidgets>

#include "cityengine.h"
#include "citytablemodel.h"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );


    CityEngine *engine = new CityEngine(QCoreApplication::instance());
    CityTableModel *model = new CityTableModel(QCoreApplication::instance());
    model->setInput(engine);
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
