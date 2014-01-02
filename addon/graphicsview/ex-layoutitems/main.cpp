
#include <QtWidgets>

/** An example that uses QGraphicsGridLayout to lay out its items in a scene */

class LayoutScene : public QGraphicsScene {
public:

    LayoutScene(QObject* parent=0) : QGraphicsScene(parent) {
        row=column=0;
        gwidget = new QGraphicsWidget();
        gridLayout = new QGraphicsGridLayout();
        gwidget->setLayout(gridLayout);
        addItem(gwidget);
    }

    void putInTheRightPlace(QGraphicsItem* item) {

        QGraphicsWidget *litem = new QGraphicsWidget(gwidget);
        QRectF r = item->boundingRect();
        litem->setMinimumSize(r.width(), r.height() + 50);
        item->setParentItem(litem);
        gridLayout->addItem(litem, row, column);

    }

    QGraphicsRectItem* createBox() {
        QGraphicsRectItem *rect = addRect(0,0,100,100, QPen(Qt::blue));
        rect->setFlags(QGraphicsItem::ItemIsMovable);
        putInTheRightPlace(rect);
        return rect;
    }


    void addBoxedItem(QGraphicsItem* item, QString title) {
        QGraphicsRectItem* box = createBox();
        item->setParentItem(box);

        QString htmlTitle = QString("<center>%1</center>").arg(title);
        QGraphicsTextItem *textItem = new QGraphicsTextItem();
        textItem->setDefaultTextColor(Qt::blue);
        QFont font;
        font.setPixelSize(10);
        textItem->setFont(font);

        textItem->setHtml(htmlTitle);

        textItem->setTextWidth(WIDTH);
        textItem->setParentItem(box);
        textItem->moveBy(0, 105);


        nextPosition();
    }

    void addBoxedShape(QAbstractGraphicsShapeItem *item, QString title) {
        item->setPen(QPen(Qt::red, 2));
        item->setBrush(Qt::yellow);
        addBoxedItem(item, title);
    }

    void nextPosition() {
        column++;
        if (column >= COLS) {
            column = 0;
            row++;
        }
    }

private:
    QGraphicsWidget *gwidget;
    QGraphicsGridLayout *gridLayout;
    enum {COLS=4};
    enum {WIDTH=100, HEIGHT=150};
    int row, column;

};

class DrawingView : public QGraphicsView {
public:

    DrawingView(QWidget* parent=0) : QGraphicsView(parent) {
        setGeometry(200,100,600,400);
        setWindowTitle("Concrete Items");
        setRenderHint(QPainter::Antialiasing);
        setRenderHint(QPainter::HighQualityAntialiasing);
        setRenderHint(QPainter::TextAntialiasing);
        setRenderHint(QPainter::SmoothPixmapTransform);
    }

    void keyPressEvent ( QKeyEvent * e ) {
        if (e->key() == Qt::Key_Escape)
            qApp->exit();
    }

    QSize sizeHint() const {
        return QSize(640, 490);
    }

};


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    DrawingView view;
    LayoutScene *scene = new LayoutScene(&view);
    view.setScene(scene);

    QPolygonF points;   
    points << QPointF(10,10) << QPointF(30,90) << QPointF(70,90) << QPointF(90,10);
    QRectF rect(QPointF(10,30), QPointF(90, 70));


    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(points);

    scene->addBoxedShape(polygonItem, "PolygonItem");

    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
    scene->addBoxedShape(rectItem, "RectItem");

    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
    scene->addBoxedShape(ellipseItem, "EllipseItem");

    QLineF line(QPointF(10,10), QPointF(90, 90));
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
    lineItem->setPen(QPen(Qt::red, 2));
    scene->addBoxedItem(lineItem, "LineItem");

    QPainterPath path;
    path.addEllipse(QRectF(10,20,80,60));
    path.addRect(QRect(10,10,80,80));

    QGraphicsPathItem *painterPathItem = new QGraphicsPathItem(path);
    painterPathItem->setPen(QPen(Qt::red, 2));
    painterPathItem->setBrush(Qt::yellow);
    scene->addBoxedItem(painterPathItem, "PainterPathItem");


    QPainterPath roundedRectPath;
    roundedRectPath.addRoundedRect(rect, 20, 20, Qt::RelativeSize);
    QGraphicsPathItem *roundedRectItem = new QGraphicsPathItem(roundedRectPath);
    roundedRectItem->setPen(QPen(Qt::red, 2));
    scene->addBoxedItem(roundedRectItem, "PainterPathItem (roundedRect)");


    QPainterPath piePath(QPointF(50, 50));
    piePath.arcTo(QRect(10,20,80,60), 45, 135);
    piePath.lineTo(50,50);
    QGraphicsPathItem *piePathItem = new QGraphicsPathItem(piePath);
    piePathItem->setPen(QPen(Qt::red, 2));
    piePathItem->setBrush(Qt::yellow);
    scene->addBoxedItem(piePathItem, "PainterPathItem (filled arc)");


    QPixmap pixmap(":/images/bg1.jpg");
    QSizeF size = pixmap.size();
    QSizeF scale = QSizeF(100.0 / size.width(), 100.0 / size.height());
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap(":/images/bg1.jpg"));
    pixmapItem->setTransform(QTransform::fromScale(scale.width(), scale.height()), true);
    scene->addBoxedItem(pixmapItem, "PixmapItem");

    view.show();
    return app.exec();

}
