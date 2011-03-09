/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SORTEDTABLEVIEW_H
#define SORTEDTABLEVIEW_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QTableView;
class QGridLayout;
class QAbstractItemModel;
class QSortFilterProxyModel;

class SortedTableView : public QWidget
{
    Q_OBJECT

public:
    explicit SortedTableView( QWidget *parent = 0 );
    ~SortedTableView();

    void setModel( QAbstractItemModel* model );

private slots:
    void setFilterColumn( int );

private:
    QSortFilterProxyModel *_filter;
    QGridLayout *_layout;
    QTableView *_tableView;
    QLabel *_label;
    QLineEdit *_lineEdit;
};


#endif
