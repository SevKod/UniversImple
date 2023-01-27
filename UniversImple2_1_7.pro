QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#INCLUDEPATH += /usr/local/include/opencv4

#LIBS += /usr/local/lib/libopencv_highgui.so
#LIBS += /usr/local/lib/libopencv_core.so.406
#LIBS += /usr/local/lib/libopencv_imgproc.so.406

INCLUDEPATH += C:\opencv\opencv\build\include

LIBS += C:\opencv\opencv\build\x64\vc15\lib\opencv_world460.lib
LIBS += C:\opencv\opencv\build\x64\vc15\lib\opencv_world460d.lib

QT += charts


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accreditation.cpp \
    apropos.cpp \
    biblio.cpp \
    bibliotheque.cpp \
    fentr.cpp \
    fonctions.cpp \
    frequentiel.cpp \
    histogramme.cpp \
    main.cpp \
    traitement.cpp \
    universimple.cpp

HEADERS += \
    accreditation.h \
    apropos.h \
    biblio.h \
    bibliotheque.h \
    fentr.h \
    fonctions.h \
    frequentiel.h \
    histogramme.h \
    traitement.h \
    universimple.h

FORMS += \
    accreditation.ui \
    apropos.ui \
    bibliotheque.ui \
    fentr.ui \
    frequentiel.ui \
    histogramme.ui \
    traitement.ui \
    universimple.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/opencv/build/x64/vc15/lib/ -lopencv_world460
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/opencv/build/x64/vc15/lib/ -lopencv_world460d

#INCLUDEPATH += $$PWD/../../../../../opencv/opencv/build/include
#DEPENDPATH += $$PWD/../../../../../opencv/opencv/build/include
