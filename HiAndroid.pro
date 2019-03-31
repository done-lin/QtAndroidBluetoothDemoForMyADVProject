#-------------------------------------------------
#
# Project created by QtCreator 2016-08-04T15:55:53
#
#-------------------------------------------------

QT       += core gui
QT      += bluetooth
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = HiAndroid
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    settinghandler.cpp

HEADERS  += widget.h \
    data_type.h \
    settinghandler.h

FORMS    += widget.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    qss.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
