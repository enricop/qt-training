#ifndef MAPCONTROLLERITEM_H_
#define MAPCONTROLLERITEM_H_

#include <QGraphicsWidget>

class QSlider;

class MapControllerItem : public QGraphicsWidget
{
    Q_OBJECT
public:
	explicit MapControllerItem( QGraphicsItem* p = 0, Qt::WindowFlags flags = 0 );
	~MapControllerItem();
	
Q_SIGNALS:
    void zoomChanged( int percents );
    
private Q_SLOTS:
    void zoomIn();
    void zoomOut();
    
private:
    QSlider* zoomSlider;
};

#endif /*MAPCONTROLLERITEM_H_*/
