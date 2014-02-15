QT += core \
    gui
QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets
TARGET = qt-opencv-multithreaded
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += . \
    /usr/local/include/opencv \
    /usr/local/lib \
    /usr/local/include \
    /usr/include/c++/4.4
DEFINES += APP_VERSION=\\\"1.3.2\\\"
SOURCES += PluginBlur.cpp \
    PluginFlip.cpp \
    PluginColorToGray.cpp \
    MyProcessing.cpp \
    PluginStack.cpp \
    PluginVision.cpp \
    FrameData.cpp \
    RingBuffer.cpp \
    main.cpp \
    MainWindow.cpp \
    MatToQImage.cpp \
    FrameLabel.cpp \
    CameraView.cpp \
    ProcessingThread.cpp \
    CaptureThread.cpp \
    CameraConnectDialog.cpp \
    ImageProcessingSettingsDialog.cpp \
    SharedImageBuffer.cpp
HEADERS += PluginBlur.h \
    PluginFlip.h \
    timer.h \
    PluginColorToGray.h \
    MyProcessing.h \
    PluginStack.h \
    PluginVision.h \
    FrameData.h \
    RingBuffer.h \
    MainWindow.h \
    Config.h \
    MatToQImage.h \
    FrameLabel.h \
    Structures.h \
    CameraView.h \
    ProcessingThread.h \
    CaptureThread.h \
    CameraConnectDialog.h \
    ImageProcessingSettingsDialog.h \
    SharedImageBuffer.h \
    Buffer.h
FORMS += MainWindow.ui \
    CameraView.ui \
    CameraConnectDialog.ui \
    ImageProcessingSettingsDialog.ui
QMAKE_CXXFLAGS += -Wall
