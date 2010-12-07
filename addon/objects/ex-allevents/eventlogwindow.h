#ifndef EVENTLOGWINDOW_H
#define EVENTLOGWINDOW_H

#include <QtGui>

class EventLogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EventLogWindow(QWidget *parent = 0);

public slots:
    void logEvent(const QString &message, QEvent *event);

private:
    QTextEdit *m_edit;
};

#endif // EVENTLOGWINDOW_H
