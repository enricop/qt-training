include (../examples.pri)
TARGET=mapviewer
OTHER_FILES += readme.txt

HEADERS += MapViewerItem.h MapControllerItem.h
SOURCES += main.cpp MapViewerItem.cpp MapControllerItem.cpp

RESOURCES += \
    maps.qrc
