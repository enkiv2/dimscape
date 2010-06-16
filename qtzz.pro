# -------------------------------------------------
# Project created by QtCreator 2010-01-16T15:37:24
# -------------------------------------------------
QT += webkit \
    multimedia \
    sql
TARGET = qtzz
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    zzspace.cpp \
    zzgraphicscell.cpp \
    Cell.cpp
HEADERS += mainwindow.h \
    zzspace.h \
    zzgraphicscell.h \
    Cell.h
FORMS += mainwindow.ui
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
