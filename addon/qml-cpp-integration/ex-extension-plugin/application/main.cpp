#include <QApplication>
#include <QDir>
#include <QDeclarativeExtensionPlugin>
#include <QDeclarativeView>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDir pluginsDir(app.applicationDirPath() + "/plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QDeclarativeExtensionPlugin *plugin = qobject_cast<QDeclarativeExtensionPlugin *>(loader.instance());
        if (plugin)
            plugin->registerTypes("Shapes");
    }

    QDeclarativeView view;
    view.setSource(QUrl("qrc:files/ellipse9.qml"));
    view.show();
    return app.exec();
}
