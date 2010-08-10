# -------------------------------------------------
# Project created by QtCreator 2010-01-16T15:37:24
# -------------------------------------------------
TEMPLATE = subdirs
SUBDIRS += backends \
	frontends \ 
	lib
CONFIG += link_pkgconfig debug
# PKGCONFIG += yaml-cpp
QMAKE_CXXFLAGS_DEBUG += -Wall
