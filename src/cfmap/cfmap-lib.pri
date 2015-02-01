ANDROID_BUNDLED_JAR_DEPENDENCIES = \
    jar/CFAndroidMap-bundled.jar
ANDROID_JAR_DEPENDENCIES = \
    jar/CFAndroidMap.jar

INCLUDEPATH += $$PWD

# Global
PUBLIC_HEADERS += \
    $$PWD/cfmap_global.h

# Map Model
PUBLIC_HEADERS += \
    $$PWD/cfmapmodel.h

PRIVATE_HEADERS += \
    $$PWD/cfmapmodel_p.h

SOURCES += \
    $$PWD/cfmapmodel.cpp

# Mark Layer
PUBLIC_HEADERS += \
    $$PWD/markerlayer/cfmapmarkerlayer.h

PRIVATE_HEADERS += \
    $$PWD/markerlayer/cfmapmarkerlayer_p.h

SOURCES += \
    $$PWD/markerlayer/cfmapmarkerlayer.cpp

# Coordinate
PUBLIC_HEADERS += \
    $$PWD/coordinate/cfmapcoordinate.h

PRIVATE_HEADERS += \
    $$PWD/coordinate/cfmapcoordinate_p.h

SOURCES += \
    $$PWD/coordinate/cfmapcoordinate.cpp

# Marker
PUBLIC_HEADERS += \
    $$PWD/marker/cfmapmarker.h

PRIVATE_HEADERS += \
    $$PWD/marker/cfmapmarker_p.h

SOURCES += \
    $$PWD/marker/cfmapmarker.cpp

# Map View
PUBLIC_HEADERS += \
    $$PWD/mapview/cfmapview.h

PRIVATE_HEADERS += \
    $$PWD/mapview/cfmapview_p.h

SOURCES += \
    $$PWD/mapview/cfmapview.cpp

# Camera Position
PUBLIC_HEADERS += \
    $$PWD/cameraposition/cfmapcameraposition.h

PRIVATE_HEADERS += \
    $$PWD/cameraposition/cfmapcameraposition_p.h

SOURCES += \
    $$PWD/cameraposition/cfmapcameraposition.cpp

android {
    QT += androidextras

    # Map Model
    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_android_p.h

    SOURCES += \
        $$PWD/cfmapmodel_android_p.cpp

    # Mark Layer
    PRIVATE_HEADERS += \
        $$PWD/markerlayer/cfmapmarkerlayer_android_p.h

    SOURCES += \
        $$PWD/markerlayer/cfmapmarkerlayer_android_p.cpp

    # coordinate
    PRIVATE_HEADERS += \
        $$PWD/coordinate/cfmapcoordinate_android_p.h

    SOURCES += \
        $$PWD/coordinate/cfmapcoordinate_android_p.cpp

    # Marker
    PRIVATE_HEADERS += \
        $$PWD/marker/cfmapmarker_android_p.h

    SOURCES += \
        $$PWD/marker/cfmapmarker_android_p.cpp

    # Map View
    PRIVATE_HEADERS += \
        $$PWD/mapview/cfmapview_android_p.h

    SOURCES += \
        $$PWD/mapview/cfmapview_android_p.cpp

    # Camera Position
    PRIVATE_HEADERS += \
        $$PWD/cameraposition/cfmapcameraposition_android_p.h

    SOURCES += \
        $$PWD/cameraposition/cfmapcameraposition_android_p.cpp

} else:ios {
    QMAKE_OBJECTIVE_CFLAGS += -F $$clean_path($$PWD/../libs) -framework GoogleMaps
    INCLUDEPATH += $$clean_path($$PWD/../libs/GoogleMaps.framework/Headers)
    INCLUDEPATH += $$clean_path($$PWD/../libs)

    # Map Model
    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/cfmapmodel_ios_p.mm

    # Mark Layer
    PRIVATE_HEADERS += \
        $$PWD/markerlayer/cfmapmarkerlayer_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/markerlayer/cfmapmarkerlayer_ios_p.mm

    # coordinate
    PRIVATE_HEADERS += \
        $$PWD/coordinate/cfmapcoordinate_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/coordinate/cfmapcoordinate_ios_p.mm

    # Marker
    PRIVATE_HEADERS += \
        $$PWD/marker/cfmapmarker_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/marker/cfmapmarker_ios_p.mm

    # Map View
    PRIVATE_HEADERS += \
        $$PWD/mapview/cfmapview_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/mapview/cfmapview_ios_p.mm

    # Camera Position
    PRIVATE_HEADERS += \
        $$PWD/cameraposition/cfmapcameraposition_ios_p.h

    OBJECTIVE_SOURCES += \
        $$PWD/cameraposition/cfmapcameraposition_ios_p.mm

} else {

    # Map Model
    PRIVATE_HEADERS += \
        $$PWD/cfmapmodel_default_p.h

    SOURCES += \
        $$PWD/cfmapmodel_default_p.cpp

    # Mark Layer
    PRIVATE_HEADERS += \
        $$PWD/markerlayer/cfmapmarkerlayer_default_p.h

    SOURCES += \
        $$PWD/markerlayer/cfmapmarkerlayer_default_p.cpp

    # coordinate
    PRIVATE_HEADERS += \
        $$PWD/coordinate/cfmapcoordinate_default_p.h

    SOURCES += \
        $$PWD/coordinate/cfmapcoordinate_default_p.cpp

    # Marker
    PRIVATE_HEADERS += \
        $$PWD/marker/cfmapmarker_default_p.h

    SOURCES += \
        $$PWD/marker/cfmapmarker_default_p.cpp

    # Map View
    PRIVATE_HEADERS += \
        $$PWD/mapview/cfmapview_default_p.h

    SOURCES += \
        $$PWD/mapview/cfmapview_default_p.cpp

    # Camera Position
    PRIVATE_HEADERS += \
        $$PWD/cameraposition/cfmapcameraposition_default_p.h

    SOURCES += \
        $$PWD/cameraposition/cfmapcameraposition_default_p.cpp
}

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS

