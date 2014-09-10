#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T11:25:21
#
#-------------------------------------------------

QT       += core \
            widgets

TARGET = Grafos
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        queue.cpp \
        graph.cpp \
        vertex.cpp \
        edge.cpp \
        Algorithms/breadthfirstsearch.cpp \
        Algorithms/deepfirstsearch.cpp \
        Algorithms/kruskal.cpp \
    element.cpp \
    Algorithms/prim.cpp \
    Algorithms/topologicalsort.cpp

HEADERS  += mainwindow.h \
        queue.h \
        graph.h \
        vertex.h \
        edge.h \
        Algorithms/breadthfirstsearch.h \
        Algorithms/deepfirstsearch.h \
        Algorithms/kruskal.h \
    element.h \
    Algorithms/prim.h \
    Algorithms/topologicalsort.h

FORMS    += mainwindow.ui
