/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

QStandardItem *createItem(int row, int col) {
    QString text = QString("(%1,%2)").arg(row).arg(col);
    QStandardItem *item = new QStandardItem(text);
    return item;
}


void createItemStructure(QStandardItemModel *model) {
    for(int row=0; row<4; row++) { // 4 rows
        for(int col=0; col<3; col++) { // each 3 columns
            QStandardItem *item = createItem(row, col);
            if(col == 0) { // on 1st column append child item
                item->appendRow(createItem(0, col));
            }
            model->setItem(row, col, item);
        }
    }
}

void createSimpleStructue(QStandardItemModel *model)
{
    model->appendRow(new QStandardItem("(0,0)"));
    model->setItem(0,1, new QStandardItem("(0,1)"));
    QStandardItem *item2 = new QStandardItem("(1,0)");
    model->appendRow(item2);
    model->setItem(1,1, new QStandardItem("(1,1)"));
    item2->appendRow(new QStandardItem("(0,0)"));
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QSplitter *widget = new QSplitter(Qt::Vertical);


    QListView *list = new QListView();
    QTableView *table = new QTableView();
    QTreeView *tree = new QTreeView();

    widget->addWidget(list);
    widget->addWidget(table);
    widget->addWidget(tree);

    QStandardItemModel *model = new QStandardItemModel(list);
    list->setModel(model);
    table->setModel(model);
    tree->setModel(model);

    // synchronize selection models
    list->setSelectionModel(tree->selectionModel());
    table->setSelectionModel(tree->selectionModel());

    model->setHorizontalHeaderItem(0, new QStandardItem("Column 0"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Column 1"));
    table->verticalHeader()->hide();
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

//    createSimpleStructue(model);
    createItemStructure(model);

    widget->show();
    app.setStyle("cleanlooks");

    return app.exec();
}
