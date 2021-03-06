#-------------------------------------------------
#
# Project created by QtCreator 2017-12-14T09:58:18
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = funcRealce
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    realce.cpp
INCLUDEPATH += "C:\OpenCV-QT\OpenCV-QT\install\include"
LIBS += -L"C:\OpenCV-QT\OpenCV-QT\install\x86\mingw\bin" \
    libopencv_core320 \
    libopencv_highgui320 \
    libopencv_videoio320 \
    libopencv_imgcodecs320 \
    libopencv_imgproc320 \
    libopencv_features2d320 \
    libopencv_calib3d320
LIBS += C:\OpenCV-QT\OpenCV-QT\lib\libopencv_imgcodecs320.dll.a

HEADERS += \
    realce.h


