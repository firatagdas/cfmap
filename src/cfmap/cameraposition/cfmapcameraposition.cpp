#include "cfmapcameraposition.h"
#include "cfmapcameraposition_p.h"

CFMapCameraPosition::CFMapCameraPosition(QObject *parent)
    : QObject(parent)
    , d_ptr(CFMapCameraPositionPrivate::create(this))
{
}

CFMapCameraPosition::~CFMapCameraPosition()
{
    delete d_ptr;
}

void CFMapCameraPosition::setTarget(CFMapCoordinate *target)
{
    Q_D(CFMapCameraPosition);
    d->setTarget(target);
}

CFMapCoordinate *CFMapCameraPosition::target() const
{
    Q_D(const CFMapCameraPosition);
    return d->target();
}

void CFMapCameraPosition::setZoom(qreal zoom)
{
    Q_D(CFMapCameraPosition);
    d->setZoom(zoom);
}

qreal CFMapCameraPosition::zoom() const
{
    Q_D(const CFMapCameraPosition);
    return d->zoom();
}

void CFMapCameraPosition::setBearing(qreal bearing)
{
    Q_D(CFMapCameraPosition);
    d->setBearing(bearing);
}

qreal CFMapCameraPosition::bearing() const
{
    Q_D(const CFMapCameraPosition);
    return d->bearing();
}

void CFMapCameraPosition::setViewingAngle(qreal viewingAngle)
{
    Q_D(CFMapCameraPosition);
    d->setViewingAngle(viewingAngle);
}

qreal CFMapCameraPosition::viewingAngle() const
{
    Q_D(const CFMapCameraPosition);
    return d->viewingAngle();
}

void *CFMapCameraPosition::nativeObject() const
{
    Q_D(const CFMapCameraPosition);
    return (void *) d->nativeObject();
}
