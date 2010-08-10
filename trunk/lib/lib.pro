QT -= gui
MAKEFILE = Makefile.qt
CONFIG += qt dll
TARGET = zz
VERSION = 1.0.0
!isEmpty(prefix) {
	unix:target.path = $${prefix}/lib
	win32:target.path = $${prefix}/Dimscape
	INSTALLS += target
}
TEMPLATE = lib
INCLUDEPATH += ../
SOURCES += ZZCell.cpp
HEADERS += ZZCell.h \
	backends/zzbackend.h
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
