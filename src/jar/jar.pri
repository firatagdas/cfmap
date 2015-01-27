load(qt_build_paths)
CONFIG += java
DESTDIR = $$MODULE_BASE_OUTDIR/jar
API_VERSION = android-11

JAVACLASSPATH += $$PWD/src

JAVASOURCES += $$PWD/src/com/cf/map/CFAndroidMapController.java
JAVACLASSPATH += \
    $$(ANDROID_HOME)/extras/google/google_play_services/libproject/google-play-services_lib/libs/google-play-services.jar \
    $$(ANDROID_HOME)/extras/android/support/v4/android-support-v4.jar

# install
target.path = $$[QT_INSTALL_PREFIX]/jar
INSTALLS += target
