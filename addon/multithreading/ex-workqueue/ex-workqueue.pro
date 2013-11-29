TARGET = ex-workqueue
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .
MOC_DIR = build
OBJECTS_DIR = build

HEADERS = workitem.h \
          workqueue.h

SOURCES = main.cpp \
          workitem.cpp \
          workqueue.cpp

QT += gui widgets
