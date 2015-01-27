#include "cfmapview_android_p.h"
#include <QtAndroidExtras>
#include <QJsonDocument>
#include <CFMvc/cfandroidutil.h>
#include <CFMvc/cfmodel.h>

CFMVC_DEFINE_PRIVATE_GLOBAL_INSTANCE(CFMapViewAndroidPrivate)

static const char androidMapControllerClass[] = "com/cf/map/CFAndroidMapController";

CFMapViewPrivate *CFMapViewPrivate::create(CFMapView *q)
{
    return new CFMapViewAndroidPrivate(q);
}

CFMapViewAndroidPrivate::CFMapViewAndroidPrivate(CFMapView *q)
    : CFMapViewPrivate(q)
    , m_id(reinterpret_cast<quintptr>(this))
{
    m_mapController = QJNIObjectPrivate(androidMapControllerClass,
                                          "(Landroid/app/Activity;J)V",
                                          QtAndroidPrivate::activity());

    m_mapView = m_mapController.callObjectMethod("getMapView", "()Lcom/google/android/gms/maps/MapView;");

    QAndroidJniEnvironment env;
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

CFMapViewAndroidPrivate::~CFMapViewAndroidPrivate()
{
}

void *CFMapViewAndroidPrivate::nativeView()
{
    return (void *) m_mapView.object();
}


