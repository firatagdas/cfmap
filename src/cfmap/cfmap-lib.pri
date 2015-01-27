ANDROID_BUNDLED_JAR_DEPENDENCIES = \
    jar/CFAndroidMap-bundled.jar
ANDROID_JAR_DEPENDENCIES = \
    jar/CFAndroidMap.jar

INCLUDEPATH += $$PWD

PUBLIC_HEADERS += \
    $$PWD/cfmap_global.h \
    $$PWD/cfmapmodel.h \
    $$PWD/cfmapview.h

PRIVATE_HEADERS += \
    $$PWD/cfmapmodel_p.h \
    $$PWD/cfmapview_p.h

SOURCES += \
    $$PWD/cfmapmodel.cpp \
    $$PWD/cfmapview.cpp

android {
    QT += androidextras

    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_android_p.h \
        $$PWD/cfmapview_android_p.h

    SOURCES += \
        $$PWD/cfmapmodel_android_p.cpp \
        $$PWD/cfmapview_android_p.cpp

} else:ios {
    QMAKE_OBJECTIVE_CFLAGS += -F $$clean_path($$PWD/../libs) -framework GoogleMaps
    INCLUDEPATH += $$clean_path($$PWD/../libs/GoogleMaps.framework/Headers)
    INCLUDEPATH += $$clean_path($$PWD/../libs)

    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_ios_p.h \
        $$PWD/cfmapview_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/cfmapmodel_ios_p.mm \
        $$PWD/cfmapview_ios_p.mm

} else {

    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_default_p.h

    SOURCES += \
        $$PWD/cfmapmodel_default_p.cpp
}

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS

