#ifndef MAPVIEWERITEM_H
#define MAPVIEWERITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class MapViewerItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    
public:
    explicit MapViewerItem( QGraphicsItem* p = 0 );
    ~MapViewerItem();

public Q_SLOTS:
    void zoom( int percent );
    
};

#endif // MAPVIEWERITEM_H
