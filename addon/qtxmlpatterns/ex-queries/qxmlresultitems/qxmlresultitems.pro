SOURCES += main.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug
TARGET = qxmlresultitems

QT -= gui
QT += xmlpatterns

