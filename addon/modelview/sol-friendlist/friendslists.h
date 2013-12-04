#ifndef FRIENDSLISTS_H
#define FRIENDSLISTS_H

#include <QDialog>
#include <QModelIndex>
#include "friendslistmodel.h"
#include "contactproxymodel.h"

namespace Ui {
    class FriendsLists;
}

/** A dialog that allows you to select people from a list on the left,
    and select/deselect their friends from a list on the right. */
class FriendsLists : public QDialog
{
    Q_OBJECT
public:
    explicit FriendsLists(QWidget *parent = 0);
    ~FriendsLists();
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_addButton_clicked();
private:
    QString m_lastSelected;
    Ui::FriendsLists *ui;
    FriendsList m_friendsList;
    // list on right:
    FriendsListModel *m_cmodel;
    // list on left:
    ContactProxyModel *m_cpmodel;

};

#endif // FRIENDSLISTS_H
