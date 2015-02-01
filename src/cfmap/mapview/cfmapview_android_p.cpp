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


void CFMapViewAndroidPrivate::setScrollGestures(bool value)
{

}

bool CFMapViewAndroidPrivate::scrollGestures() const
{

}

void CFMapViewAndroidPrivate::setZoomGestures(bool value)
{

}

bool CFMapViewAndroidPrivate::zoomGestures() const
{

}

void CFMapViewAndroidPrivate::setTiltGestures(bool value)
{

}

bool CFMapViewAndroidPrivate::tiltGestures() const
{

}

void CFMapViewAndroidPrivate::setRotateGestures(bool value)
{

}

bool CFMapViewAndroidPrivate::rotateGestures() const
{

}

void CFMapViewAndroidPrivate::setConsumesGesturesInView(bool value)
{

}

bool CFMapViewAndroidPrivate::consumesGesturesInView() const
{

}

void CFMapViewAndroidPrivate::setCompassButton(bool value)
{

}

bool CFMapViewAndroidPrivate::compassButton() const
{

}

void CFMapViewAndroidPrivate::setMyLocationButton(bool value)
{

}

bool CFMapViewAndroidPrivate::myLocationButton() const
{

}

void CFMapViewAndroidPrivate::setIndoorPicker(bool value)
{

}

bool CFMapViewAndroidPrivate::indoorPicker() const
{

}

void CFMapViewAndroidPrivate::setMapType(int mapType)
{

}

int CFMapViewAndroidPrivate::mapType() const
{

}

void CFMapViewAndroidPrivate::clear()
{

}

void CFMapViewAndroidPrivate::setZoomRange(int min, int max)
{

}

void CFMapViewAndroidPrivate::animateToCameraPosition(CFMapCameraPosition *position)
{

}

void CFMapViewAndroidPrivate::animateToLocation(CFMapCoordinate *coordinate)
{

}

void CFMapViewAndroidPrivate::animateToZoom(qreal zoom)
{

}

void CFMapViewAndroidPrivate::animateToBearing(qreal bearing)
{

}

void CFMapViewAndroidPrivate::animateToViewingAngle(qreal viewingAngle)
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateZoomIn()
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateZoomOut()
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateZoomBy(qreal delta)
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateZoomTo(qreal zoom)
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target)
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom)
{

}

void CFMapViewAndroidPrivate::animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition)
{

}

