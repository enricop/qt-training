#ifndef SELECTCOLOR_H
#define SELECTCOLOR_H

#include <QWidget>

class QLabel;

class SelectColor : public QWidget
{
public:
    SelectColor(QWidget *parent = 0);

private:
    QLabel *m_label;
};


#endif // SELECTCOLOR_H
