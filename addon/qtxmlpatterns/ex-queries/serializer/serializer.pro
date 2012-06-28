SOURCES += main.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug
TARGET = serialize

QT -= gui
QT += xmlpatterns

