QT -= gui
CONFIG += qt staticlib
MAKEFILE = Makefile.qt
TARGET = backend
TEMPLATE = lib
INCLUDEPATH += ../
HEADERS += zzbackend.h
sql-backend {
	QT += sql
	SOURCES += zzsqlbackend.cpp
	HEADERS += zzsqlbackend.h
} else {
	error("You must select a backend: sql-backend, ...")
}
CONFIG += debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
