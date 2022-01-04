QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cartdevicewidget.cpp \
    cartwidget.cpp \
    currentuser.cpp \
    dbmanager.cpp \
    devicetype.cpp \
    devicewidget.cpp \
    imagetype.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    signinwindow.cpp \
    signupwindow.cpp \
    user.cpp

HEADERS += \
    cartdevicewidget.h \
    cartwidget.h \
    currentuser.h \
    dbmanager.h \
    device.h \
    devicetype.h \
    devicewidget.h \
    imagetype.h \
    mainwidget.h \
    mainwindow.h \
    newuser.h \
    signinwindow.h \
    signupwindow.h \
    user.h \
    usertype.h

FORMS += \
    cartdevicewidget.ui \
    cartwidget.ui \
    devicewidget.ui \
    mainwidget.ui \
    mainwindow.ui \
    signinwindow.ui \
    signupwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
