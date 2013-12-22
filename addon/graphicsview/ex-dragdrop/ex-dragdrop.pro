QT += core gui widgets

TEMPLATE = app
TARGET = diagram 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += diagramitem.h diagramscene.h mainwindow.h toolbox.h
SOURCES += diagramitem.cpp diagramscene.cpp main.cpp mainwindow.cpp toolbox.cpp
win32 {
    MOC_DIR = _moc
    OBJECTS_DIR = _obj
} else {
    MOC_DIR = .moc
    OBJECTS_DIR = .obj
}
