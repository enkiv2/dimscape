# -------------------------------------------------
# Project created by QtCreator 2010-01-16T15:37:24
# -------------------------------------------------
QT += webkit \
    phonon \
    multimedia \
    sql
TARGET = qtzz
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    zzspace.cpp \
    zzcell.cpp \
    zzgraphicscell.cpp \
    Cell.cpp
HEADERS += mainwindow.h \
    zzspace.h \
    zzcell.h \
    zzgraphicscell.h \
    Cell.h
FORMS += mainwindow.ui
CONFIG += link_pkgconfig
# PKGCONFIG += yaml-cpp
