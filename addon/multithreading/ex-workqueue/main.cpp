#include <QApplication>
#include <QtDebug>

#include "workqueue.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    WorkQueue workqueue(4);
    workqueue.show();

    app.exec();
    qDebug() << "Program Exited" << endl;
}
