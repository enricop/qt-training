TARGET = sol-threaded-progress
TEMPLATE = app
QT += widgets

SOURCES += \
    main.cpp\
    progresswindow.cpp \
    worker.cpp \
    work.cpp

HEADERS += \
    progresswindow.h \
    worker.h
MOC_DIR = build
OBJECTS_DIR = build
