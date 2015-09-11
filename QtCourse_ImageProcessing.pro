#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T11:39:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCourse_ImageProcessing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

INCLUDEPATH += C:\\Qt\\opencv_v3.0_x86\\include    \
                C:\\Qt\\opencv_v3.0_x86\\include\\opencv    \
                C:\\Qt\\opencv_v3.0_x86\\include\\opencv2   \

#debug libs
LIBS += C:\\Qt\\opencv_v3.0_x86\\lib\\opencv_world300.lib \
        C:\\Qt\\opencv_v3.0_x86\\lib\\opencv_ts300.lib  \
#release libs
        C:\\Qt\\opencv_v3.0_x86\\lib\\opencv_world300d.lib \
        C:\\Qt\\opencv_v3.0_x86\\lib\\opencv_ts300d.lib

FORMS    += mainwindow.ui
