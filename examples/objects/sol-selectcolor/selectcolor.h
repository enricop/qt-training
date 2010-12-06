#ifndef SELECTCOLOR_H
#define SELECTCOLOR_H

#include <QtGui>

class QLabel;

class SelectColor : public QWidget
{
    Q_OBJECT

public:
    SelectColor(QWidget *parent = 0);

public slots:
    void slotSelectColor();

private:
    QLabel *m_label;
};

#endif // SELECTCOLOR_H
