QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    bronx.cpp \
    brooklyn.cpp \
    diabetes.cpp \
    directory.cpp \
    hypertension.cpp \
    main.cpp \
    mainwindow.cpp \
    manhattan.cpp \
    obesity.cpp \
    queens.cpp \
    statenisland.cpp

HEADERS += \
    about.h \
    borough.h \
    bronx.h \
    brooklyn.h \
    diabetes.h \
    directory.h \
    hypertension.h \
    mainwindow.h \
    manhattan.h \
    obesity.h \
    queens.h \
    statenisland.h

FORMS += \
    about.ui \
    bronx.ui \
    brooklyn.ui \
    diabetes.ui \
    hypertension.ui \
    mainwindow.ui \
    manhattan.ui \
    obesity.ui \
    queens.ui \
    statenisland.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
