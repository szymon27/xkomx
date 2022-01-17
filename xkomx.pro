QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewcomputerwidget.cpp \
    addnewdevicewindow.cpp \
    addnewkeyboardwidget.cpp \
    addnewmonitorwidget.cpp \
    addnewmousewidget.cpp \
    adminpanelwindow.cpp \
    cart.cpp \
    cartdevicewidget.cpp \
    cartwidget.cpp \
    computer.cpp \
    currentuser.cpp \
    dbmanager.cpp \
    device.cpp \
    devicetype.cpp \
    devicewidget.cpp \
    displaytype.cpp \
    edituserwindow.cpp \
    idevicedetails.cpp \
    imagetype.cpp \
    keyboard.cpp \
    keyboardtype.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    managerdevicewidget.cpp \
    manageruserwidget.cpp \
    monitor.cpp \
    mouse.cpp \
    order.cpp \
    orderdetailswindow.cpp \
    orderhistorydetailswindow.cpp \
    orderhistorydevicewidget.cpp \
    orderhistorywidget.cpp \
    orderhistorywindow.cpp \
    signinwindow.cpp \
    signupwindow.cpp \
    user.cpp \
    usertype.cpp

HEADERS += \
    addnewcomputerwidget.h \
    addnewdevicewindow.h \
    addnewkeyboardwidget.h \
    addnewmonitorwidget.h \
    addnewmousewidget.h \
    adminpanelwindow.h \
    cart.h \
    cartdevicewidget.h \
    cartwidget.h \
    computer.h \
    currentuser.h \
    dbmanager.h \
    device.h \
    devicetype.h \
    devicewidget.h \
    displaytype.h \
    edituserwindow.h \
    idevicedetails.h \
    imagetype.h \
    keyboard.h \
    keyboardtype.h \
    mainwidget.h \
    mainwindow.h \
    managerdevicewidget.h \
    manageruserwidget.h \
    monitor.h \
    mouse.h \
    newuser.h \
    order.h \
    orderdetailswindow.h \
    orderhistorydetailswindow.h \
    orderhistorydevicewidget.h \
    orderhistorywidget.h \
    orderhistorywindow.h \
    signinwindow.h \
    signupwindow.h \
    user.h \
    usertype.h

FORMS += \
    addnewcomputerwidget.ui \
    addnewdevicewindow.ui \
    addnewkeyboardwidget.ui \
    addnewmonitorwidget.ui \
    addnewmousewidget.ui \
    adminpanelwindow.ui \
    cartdevicewidget.ui \
    cartwidget.ui \
    devicewidget.ui \
    edituserwindow.ui \
    mainwidget.ui \
    mainwindow.ui \
    managerdevicewidget.ui \
    manageruserwidget.ui \
    orderdetailswindow.ui \
    orderhistorydetailswindow.ui \
    orderhistorydevicewidget.ui \
    orderhistorywidget.ui \
    orderhistorywindow.ui \
    signinwindow.ui \
    signupwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
