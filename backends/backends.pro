CONFIG += qt staticlib
TARGET = backend
TEMPLATE = lib
HEADERS += zzbackend.h
sql-backend {
	SOURCES += zzsqlbackend.cpp
	HEADERS +=	zzsqlbackend.h
}
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
