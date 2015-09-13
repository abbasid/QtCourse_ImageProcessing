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

INCLUDEPATH += C:\\opencv_v3.0\\x64\\include    \
                C:\\opencv_v3.0\\x64\\include\\opencv    \
                C:\\opencv_v3.0\\x64\\include\\opencv2   \

#debug libs
LIBS += C:\\opencv_v3.0\\x64\\lib\\opencv_world300.lib \
        C:\\opencv_v3.0\\x64\\lib\\opencv_ts300.lib  \
#release libs
        C:\\opencv_v3.0\\x64\\lib\\opencv_world300d.lib \
        C:\\opencv_v3.0\\x64\\lib\\opencv_ts300d.lib

FORMS    += mainwindow.ui
