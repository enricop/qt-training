TEMPLATE=app

HEADERS += pictureitem.h \
    corneritem.h \
    mainwindow.h

SOURCES += \
    pictureitem.cpp \
    corneritem.cpp \
    mainwindow.cpp \
    main.cpp

FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc
    
OTHER_FILES += \
    README.txt    

QT += widgets
