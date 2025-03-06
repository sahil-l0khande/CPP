QT       += core gui \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assign_18.cpp \
    main.cpp \
    mainwindow.cpp \
    remove_4.cpp \
    scenario_3.cpp \
    scenario_4.cpp \
    scenario_5.cpp \
    search_18.cpp \
    search_4.cpp

HEADERS += \
    Headers/layoutExample.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
