QT += quick

SOURCES += main.cpp \
           citymodel.cpp \
           ../cityengine/cityengine.cpp

HEADERS += citymodel.h \
           ../cityengine/cityengine.h

INCLUDEPATH += ../cityengine

RESOURCES += sol-cities-custom.qrc \
             ../cityengine/cities.qrc

OTHER_FILES += main.qml
