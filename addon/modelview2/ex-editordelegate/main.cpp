/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>


class CountryDelegate :public QItemDelegate
{
public:
    explicit CountryDelegate(QStringList countries, QObject *parent=0)
        : QItemDelegate(parent), m_countries(countries){
    }

    virtual QWidget* createEditor ( QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index ) const
    {
        if ( index.column() == 0 ) {
            QComboBox* editor = new QComboBox( parent );
            editor->addItems( m_countries );
            return editor;
        } else {
            QWidget *editor = QItemDelegate::createEditor(parent, option, index );
            editor->setAutoFillBackground(true);
            return editor;
        }
    }
    virtual void setEditorData( QWidget* editor, const QModelIndex& index ) const
    {
        if ( index.column() == 0 ) {
            QComboBox* combo = static_cast<QComboBox*>( editor );
            int idx = m_countries.indexOf( index.data( Qt::DisplayRole ).toString() );
            combo->setCurrentIndex( idx );
        } else {
            QItemDelegate::setEditorData( editor, index );
        }
    }
    virtual void setModelData( QWidget * editor, QAbstractItemModel* model, const QModelIndex& index ) const
    {
        if ( index.column() == 0 ) {
            QComboBox* combo = static_cast<QComboBox*>( editor );
            model->setData( index, combo->currentText() );
        } else {
            QItemDelegate::setModelData( editor, model, index );
        }
    }

    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem& option, const QModelIndex& index ) const
    {
        if ( index.column() == 0 ) {
            // don't allow the editor to get a smaller height than its sizehint.
            QRect rect(QPoint(0,0), option.rect.size().expandedTo(editor->sizeHint()));
            rect.moveCenter(option.rect.center());
            editor->setGeometry( rect );
        } else {
            QItemDelegate::updateEditorGeometry( editor, option, index );
        }
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QItemDelegate::sizeHint(option, index).expandedTo(QSize(64, option.fontMetrics.height()+16));
    }
private:
    QStringList m_countries;
};

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QList<int> populations;
    populations << 5432 << 9001 << 4593 << 295734 << 82431 << 38635 << 296 << 16407 << 60441 << 4015 << 5062;

    QStringList countries;
    countries << "Denmark" << "Sweden" << "Norway" << "USA" << "Germany"
              << "Poland" << "Iceland" << "Holland" << "Great Britain" << "Ireland" << "Scotland";


    QStandardItemModel* model = new QStandardItemModel( 11, 2 );
    for ( int row = 0; row < 11; ++row ) {
        model->setData( model->index( row, 0, QModelIndex() ), countries[row] );
        model->setData( model->index( row, 1, QModelIndex() ), populations[row] );
        model->setData( model->index( row, 1, QModelIndex() ), Qt::AlignRight, Qt::TextAlignmentRole );
    }
    model->setHeaderData( 0, Qt::Horizontal, "Country" );
    model->setHeaderData( 1, Qt::Horizontal, "Population" );


    QListView* list = new QListView;
    list->setWindowTitle( "QListView" );
    list->setModel( model );
    list->setItemDelegate( new CountryDelegate( countries ) );
    list->show();

    QTableView* table = new QTableView;
    table->setWindowTitle( "QTableView" );
    table->setModel( model );
    table->setItemDelegate( new CountryDelegate( countries ) );
    table->show();

    QTreeView* tree = new QTreeView;
    tree->setWindowTitle( "QTreeView" );
    tree->setModel( model );
    tree->setItemDelegate( new CountryDelegate( countries ) );
    tree->show();

    return app.exec();
}