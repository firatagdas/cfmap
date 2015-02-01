#include "cfmapcameraposition_default_p.h"

CFMapCameraPositionPrivate *CFMapCameraPositionPrivate::create(CFMapCameraPosition *q)
{
    return new CFMapCameraPositionDefaultPrivate(q);
}


CFMapCameraPositionDefaultPrivate::CFMapCameraPositionDefaultPrivate(CFMapCameraPosition *q)
    : CFMapCameraPositionPrivate(q)
{
}

CFMapCameraPositionDefaultPrivate::~CFMapCameraPositionDefaultPrivate()
{
}


void CFMapCameraPositionDefaultPrivate::setTarget(CFMapCoordinate *target)
{
}

CFMapCoordinate *CFMapCameraPositionDefaultPrivate::target() const
{
    return 0;
}

void CFMapCameraPositionDefaultPrivate::setZoom(qreal zoom)
{
}

qreal CFMapCameraPositionDefaultPrivate::zoom() const
{
    return 0;
}

void CFMapCameraPositionDefaultPrivate::setBearing(qreal bearing)
{
}

qreal CFMapCameraPositionDefaultPrivate::bearing() const
{
    return 0;
}

void CFMapCameraPositionDefaultPrivate::setViewingAngle(qreal viewingAngle)
{
}

qreal CFMapCameraPositionDefaultPrivate::viewingAngle() const
{
    return 0;
}

void *CFMapCameraPositionDefaultPrivate::nativeObject() const
{
    return 0;
}
