QT += widgets
TEMPLATE = lib
DEFINES += ROADEDITOR_LIBRARY

CONFIG += c++11 plugin

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS +=

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    RoadEditor.json

win32:CONFIG(release, debug|release) {
    DESTDIR = $$PWD/../build/release
} else:win32:CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../build/debug
}

FORMS +=
include(ViewWindow.pri)
include(PropertyWindow.pri)
include(SceneWindow.pri)
include(../Common/Common.pri)
include(SceneWindowObjects.pri)
include(FileOpsMenu.pri)
include(Interface.pri)
include(Model.pri)
include(SourcePackageManager.pri)
include(SceneWindowMenu.pri)
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Depend/lib/ -lassimp-vc142-mt
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Depend/lib/ -lassimp-vc142-mtd
#else:unix: LIBS += -L$$PWD/../Depend/lib/ -lassimp-vc142-mt

#INCLUDEPATH += $$PWD/../Depend/include
#DEPENDPATH += $$PWD/../Depend/include
