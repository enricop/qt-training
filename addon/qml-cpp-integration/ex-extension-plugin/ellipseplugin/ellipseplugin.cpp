#include <qdeclarative.h>
#include "ellipseplugin.h"
#include "ellipseitem.h"

void EllipsePlugin::registerTypes(const char *uri)
{
    qmlRegisterType<EllipseItem>(uri, 9, 0, "Ellipse");
}

Q_EXPORT_PLUGIN2(ellipseplugin, EllipsePlugin);
