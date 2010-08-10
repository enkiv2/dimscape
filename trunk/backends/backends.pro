CONFIG += qt staticlib
TARGET = backend
TEMPLATE = lib
INCLUDEPATH += ../
HEADERS += zzbackend.h \
	ZZCell.h
sql-backend {
	SOURCES += zzsqlbackend.cpp
	HEADERS +=	zzsqlbackend.h
} else {
	error("You must select a backend: sql-backend, ...")
}
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
