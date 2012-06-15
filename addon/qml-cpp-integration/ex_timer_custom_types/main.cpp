#include "timer.h"
#include "IntervalSettings.h"

#include <QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication app( argc, argv );

    qsrand( QDateTime::currentMSecsSinceEpoch() );

    // Expose the Timer class
    qmlRegisterType<Timer>( "CustomComponents", 1, 0, "Timer" );
    qmlRegisterType<IntervalSettings>( "CustomComponents", 1, 0, "IntervalSettings");

    QDeclarativeView viewer;
    viewer.setSource( QUrl( "qrc:/main.qml" ) );
    viewer.show();

    return app.exec();
}
