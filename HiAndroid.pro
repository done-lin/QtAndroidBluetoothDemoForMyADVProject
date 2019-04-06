#-------------------------------------------------
#
# Project created by QtCreator 2016-08-04T15:55:53
#
#-------------------------------------------------

QT      += core gui
QT      += bluetooth
QT      += androidextras
QT      += core-private
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = HiAndroid
TEMPLATE = app
contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        $$PWD/lib/openssl/libcrypto.so \
        $$PWD/lib/openssl/libssl.so
}

SOURCES += main.cpp\
        widget.cpp \
    settinghandler.cpp \
    advgetwebinfo.cpp \
    permissions.cpp

HEADERS  += widget.h \
    data_type.h \
    settinghandler.h \
    advgetwebinfo.h \
    permissions.h

##
## LIBS+=-lcrypto
## LIBS+=-lssl

FORMS    += widget.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    qss.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
