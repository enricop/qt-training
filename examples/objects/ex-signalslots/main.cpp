#include <QtGui>
#include "myemitter.h"
#include "myreceiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyEmitter *emitter = new MyEmitter("Hello World");
    MyReceiver *receiver = new MyReceiver;
    QObject::connect(emitter, SIGNAL(aSignal()), receiver, SLOT(aSlot()));

    emitter->show();

    return app.exec();
}
