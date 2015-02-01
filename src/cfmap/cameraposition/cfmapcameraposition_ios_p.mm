#include "cfmapcameraposition_ios_p.h"
#include "../coordinate/cfmapcoordinate.h"
#import <GoogleMaps/GoogleMaps.h>

CFMapCameraPositionPrivate *CFMapCameraPositionPrivate::create(CFMapCameraPosition *q)
{
    return new CFMapCameraPositionIosPrivate(q);
}

CFMapCameraPositionIosPrivate::CFMapCameraPositionIosPrivate(CFMapCameraPosition *q)
    : CFMapCameraPositionPrivate(q)
    , m_target(new CFMapCoordinate())
    , m_zoom(0.)
    , m_bearing(0.)
    , m_viewingAngle(0.)
    , m_cameraPosition(nil)
{
    restoreNativeObject();
}

CFMapCameraPositionIosPrivate::~CFMapCameraPositionIosPrivate()
{
    [m_cameraPosition release];
}


void CFMapCameraPositionIosPrivate::setTarget(CFMapCoordinate *target)
{
    if (m_target != target) {
        m_target = target;
        restoreNativeObject();
        Q_EMIT q()->targetChanged();
    }
}

CFMapCoordinate *CFMapCameraPositionIosPrivate::target() const
{
    return m_target;
}

void CFMapCameraPositionIosPrivate::setZoom(qreal zoom)
{
    if (m_zoom != zoom) {
        m_zoom = zoom;
        restoreNativeObject();

        Q_EMIT q()->targetChanged();
    }
}

qreal CFMapCameraPositionIosPrivate::zoom() const
{
    return m_zoom;
}

void CFMapCameraPositionIosPrivate::setBearing(qreal bearing)
{
    if (m_bearing != bearing) {
        m_bearing = bearing;
        restoreNativeObject();

        Q_EMIT q()->bearingChanged();
    }
}

qreal CFMapCameraPositionIosPrivate::bearing() const
{
    return m_bearing;
}

void CFMapCameraPositionIosPrivate::setViewingAngle(qreal viewingAngle)
{
    if (m_viewingAngle != viewingAngle) {
        m_viewingAngle = viewingAngle;
        restoreNativeObject();

        Q_EMIT q()->viewingAngleChanged();
    }
}

qreal CFMapCameraPositionIosPrivate::viewingAngle() const
{
    return m_viewingAngle;
}

void *CFMapCameraPositionIosPrivate::nativeObject() const
{
    return m_cameraPosition;
}

void CFMapCameraPositionIosPrivate::restoreNativeObject()
{
    if (m_cameraPosition != nil)
        [m_cameraPosition release];

    m_cameraPosition = [GMSCameraPosition cameraWithLatitude:m_target->latitude() longitude:m_target->longitude() zoom:m_zoom bearing:m_bearing viewingAngle:m_viewingAngle];
}
