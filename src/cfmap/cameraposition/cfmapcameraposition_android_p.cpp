#include "cfmapcameraposition_android_p.h"

CFMapCameraPositionPrivate *CFMapCameraPositionPrivate::create(CFMapCameraPosition *q)
{
    return new CFMapCameraPositionAndroidPrivate(q);
}


CFMapCameraPositionAndroidPrivate::CFMapCameraPositionAndroidPrivate(CFMapCameraPosition *q)
    : CFMapCameraPositionPrivate(q)
{
}

CFMapCameraPositionAndroidPrivate::~CFMapCameraPositionAndroidPrivate()
{
}


void CFMapCameraPositionAndroidPrivate::setTarget(CFMapCoordinate *target)
{
}

CFMapCoordinate *CFMapCameraPositionAndroidPrivate::target() const
{
    return 0;
}

void CFMapCameraPositionAndroidPrivate::setZoom(qreal zoom)
{
}

qreal CFMapCameraPositionAndroidPrivate::zoom() const
{
    return 0;
}

void CFMapCameraPositionAndroidPrivate::setBearing(qreal bearing)
{
}

qreal CFMapCameraPositionAndroidPrivate::bearing() const
{
    return 0;
}

void CFMapCameraPositionAndroidPrivate::setViewingAngle(qreal viewingAngle)
{
}

qreal CFMapCameraPositionAndroidPrivate::viewingAngle() const
{
    return 0;
}

void *CFMapCameraPositionAndroidPrivate::nativeObject() const
{
    return 0;
}
