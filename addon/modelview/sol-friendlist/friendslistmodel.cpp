#include <QMessageBox>
#include "friendslistmodel.h"

QStringList FriendsList::friends(QString key)  {
    QStringList retval;
    const_iterator itr = constFind(key);
    while (itr != constEnd()) {
        retval << itr.value();
        itr++;
    }
    return retval;
}

bool FriendsList::friendsWith(QString a, QString b) const {
    if (a == b) return true;
    return constFind(a, b) != constEnd();
}

FriendsListModel::FriendsListModel(QObject *parent)
: QAbstractListModel(parent) {
    
}

Qt::ItemFlags FriendsListModel::flags(const QModelIndex &index) const {
    int r = index.row();
    if (r >= rowCount()) return 0;
    QString d = m_allPeople[r];
    
    if (d == m_contact || m_contact == QString()) 
        return 0; /* Don't let user interact with this 
                     item unless a different contact is selected 
                     on the left. */  
    return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void FriendsListModel::add(QString k) {
    int pos = 0;
    if (m_allPeople.contains(k)) {
        QMessageBox::critical(0, "Duplicate Person", "Contact already exists");
        return;
    }
    if (k == QString()) return;
    for (int i = m_allPeople.length() - 1; i >= 0; --i) {
        if (k >= m_allPeople[i]) {pos = i+1; break;}
    }
    if (pos >= rowCount()) pos = rowCount();
    if (pos < 0) pos = 0;
    beginInsertRows(QModelIndex(), pos, pos);
    m_allPeople << k;
    m_allPeople.sort();
    set(k,k);
    endInsertRows();
}


int FriendsListModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return m_allPeople.count();
}

QVariant FriendsListModel::data(const QModelIndex &index, int role) const {
    int r = index.row();
    if (r >= rowCount()) return QVariant();
    QString d = m_allPeople[index.row()];
    if ((role == Qt::DisplayRole) || (role == Qt::EditRole))
        return d;
    if ((role == Qt::CheckStateRole)) {
        return m_friendsList.friendsWith(d, m_contact);
    }
    return QVariant();
}

bool FriendsListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::CheckStateRole) { /* The item is not editable but we go here
           if the user tries to check an item that is ItemIsUserCheckable. */
        QString d = m_allPeople[index.row()];
        if (d == m_contact || m_contact == QString()) return false;
        bool isFriends = m_friendsList.friendsWith(d, m_contact);
        if (!isFriends) 
            set(m_contact, d);
        else 
            unset(m_contact, d);
        return true;
    }
    return false;
}


void FriendsListModel::contactSelected(QModelIndex idx) {
    int r = idx.row();
    QString old = m_contact;
    if (idx.isValid()) {
        m_contact = m_allPeople[r];
    }
    else m_contact = QString();
    if (old != m_contact) {
        emit dataChanged(createIndex(0,0), createIndex(rowCount(), 0));
    }
}


QModelIndex FriendsListModel::indexOf(QString key) {
    int r = m_allPeople.indexOf(key);
    return createIndex(r, 0);
}

void FriendsListModel::set(QString k1, QString k2) {
    m_friendsList.insert (k1, k2);
    m_friendsList.insert (k2, k1);
    int index1 = m_allPeople.indexOf(k1);
    int index2 = m_allPeople.indexOf(k2);
    emit dataChanged(createIndex(index1,0),createIndex(index1,0));
    emit dataChanged(createIndex(index2,0),createIndex(index2,0));
}

void FriendsListModel::unset(QString k1, QString k2) {
    if (k1 == k2) return;
    m_friendsList.remove(k1, k2);
    m_friendsList.remove(k2, k1);
    int index1 = m_allPeople.indexOf(k1);
    int index2 = m_allPeople.indexOf(k2);
    emit dataChanged(createIndex(index1,0),createIndex(index1,0));
    emit dataChanged(createIndex(index2,0),createIndex(index2,0));
}

