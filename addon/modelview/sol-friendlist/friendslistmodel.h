#ifndef FRIENDLISTMODEL_H
#define FRIENDLISTMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <QMultiMap>
#include <QString>
#include <QStringList>

/** This is the underlying data structure we wish to model */
class FriendsList : public QMultiMap<QString, QString> {
public:
    /** @return list of person's friends */
    QStringList friends(QString person) ;
    /** @return true if a is friends with b */
    bool friendsWith(QString a, QString b) const;
};

/** A ListModel for the right listview that lets you check
    and un-check friends to add/remove */
class FriendsListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FriendsListModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex indexOf(QString key) ;

    void add(QString k);
    void set(QString k1, QString k2);
    void unset(QString k1, QString k2);

public slots:
    void contactSelected(QModelIndex idx);

protected:
    QString m_contact;
    FriendsList m_friendsList;
    QStringList m_allPeople;
};

#endif // FRIENDLISTMODEL_H
