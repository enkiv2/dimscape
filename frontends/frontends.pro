# -------------------------------------------------
# Project created by QtCreator 2010-01-16T15:37:24
# -------------------------------------------------
QT += webkit \
    multimedia \
    sql
TARGET = qtzz
TEMPLATE = subdirs
SUBDIRS += backends \
	lib
SOURCES += main.cpp \
    mainwindow.cpp \
    zzspace.cpp \
    zzgraphicscell.cpp \
    lib/ZZCell.cpp \
    backends/zzsqlbackend.cpp
HEADERS += mainwindow.h \
    zzspace.h \
    zzgraphicscell.h \
    lib/ZZCell.h \
    backends/zzsqlbackend.h
FORMS += mainwindow.ui
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
