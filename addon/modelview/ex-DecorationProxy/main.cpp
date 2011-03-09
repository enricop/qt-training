/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

/**
 * We want icons in one view and not in the other:
 * we use a proxy for this.
 */
class MyProxy : public QSortFilterProxyModel
{
public:
    MyProxy(QObject * parent = 0 ) : QSortFilterProxyModel(parent),
                                     m_pixmap("tux.png")
    {
        m_pixmap = m_pixmap.scaled(32, 32);
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (index.isValid() && role == Qt::DecorationRole)
            return m_pixmap;
        return QSortFilterProxyModel::data(index, role);
    }
private:
    QPixmap m_pixmap;
};

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QStringList countries;
    countries << "Denmark" << "Norway" << "Sweden" << "USA" << "Poland";
    QStringListModel* model = new QStringListModel(countries);

    // The QListView without icons
    QListView* list = new QListView;
    list->setModel(model);
    list->setWindowTitle( "QListView" );
    list->show();

    // The QListView with icons
    QListView* list2 = new QListView;
    MyProxy* proxy = new MyProxy;
    proxy->setSourceModel(model);
    list2->setModel(proxy);
    list2->setWindowTitle( "QListView with icons" );
    list2->show();

    return app.exec();
}
