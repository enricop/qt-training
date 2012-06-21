QT += quick widgets

SOURCES += main.cpp \
           citymodel.cpp \
           ../cityengine/cityengine.cpp

HEADERS += citymodel.h \
           ../cityengine/cityengine.h

INCLUDEPATH += ../cityengine

RESOURCES += sol-cities-filter.qrc \
             ../cityengine/cities.qrc

OTHER_FILES += main.qml
