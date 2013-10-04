#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "ui_gallery.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private:
    Ui::Gallery *gallery;
};

#endif // WINDOW_H
