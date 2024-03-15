QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./view

SOURCES += \
    controller/controller.cc \
    main.cc \
    model/credit.cc \
    model/calculator.cc \
    model/token.cc \
    view/creditwindow.cc \
    view/graphwindow.cc \
    view/mainwindow.cc \
    view/qcustomplot.cc

HEADERS += \
    controller/controller.h \
    model/credit.h \
    model/calculator.h \
    model/token.h \
    view/creditwindow.h \
    view/graphwindow.h \
    view/mainwindow.h \
    view/qcustomplot.h

FORMS += \
    view/creditwindow.ui \
    view/graphwindow.ui \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
