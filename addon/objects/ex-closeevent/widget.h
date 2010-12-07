#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private:
    bool windowShouldClose();
};

#endif // WIDGET_H
