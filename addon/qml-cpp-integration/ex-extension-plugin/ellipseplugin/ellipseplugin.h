#ifndef ELLIPSEPLUGIN_H
#define ELLIPSEPLUGIN_H

#include <QDeclarativeExtensionPlugin>

class EllipsePlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    void registerTypes(const char *uri);
};

#endif

