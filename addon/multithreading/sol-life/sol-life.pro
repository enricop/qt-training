
QT       += core gui widgets concurrent

TARGET = life
TEMPLATE = app

SOURCES += main.cpp \
   lifemainwindow.cpp \
   lifewidget.cpp 

HEADERS  += lifemainwindow.h \
   lifewidget.h \
   lifeslice.h

FORMS    += lifemainwindow.ui 

