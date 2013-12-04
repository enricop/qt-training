#include <QtGui>
#include <QInputDialog>
#include "friendslistmodel.h"
#include "friendslists.h"
#include "ui_friendslists.h"


FriendsLists::FriendsLists(QWidget *parent) 
: QDialog(parent), ui(new Ui::FriendsLists) {
    ui->setupUi(this);
    m_cmodel = new FriendsListModel(m_friendsList, this);
    m_cmodel->add("a");
    m_cmodel->add("z");
    m_cmodel->add("m");
    m_cmodel->add("b");
    //m_cmodel->updateAllPeople();
    m_cpmodel = new ContactProxyModel(this);
    m_cpmodel->setSourceModel(m_cmodel);
    ui->contactsListView->setModel(m_cpmodel);
    ui->friendsListView->setModel(m_cmodel);
    connect (ui->contactsListView, SIGNAL(clicked(QModelIndex)),
             m_cmodel, SLOT(contactSelected(QModelIndex)));
}

FriendsLists::~FriendsLists() {
    delete ui;
}

void FriendsLists::changeEvent(QEvent *e) {
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void FriendsLists::on_addButton_clicked() {
    QString str = QInputDialog::getText(this, 
        tr("Enter a symbol"), tr("Symbol: ") );
    if (str == QString()) return;
    m_cmodel->add(str);
}
