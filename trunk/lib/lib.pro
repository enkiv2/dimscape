QT -= gui
CONFIG += qt dll
TARGET = zz
TEMPLATE = lib
INCLUDEPATH += ../
SOURCES += ZZCell.cpp
HEADERS += ZZCell.h \
	backends/zzbackend.h
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
