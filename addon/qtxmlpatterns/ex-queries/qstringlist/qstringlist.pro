SOURCES += main.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug
TARGET = qstringlist

QT -= gui
QT += xmlpatterns

