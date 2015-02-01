#include "cfmapmarkerlayer.h"
#include "cfmapmarkerlayer_p.h"

CFMapMarkerLayer::CFMapMarkerLayer(QObject *parent)
    : QObject(parent)
    , d_ptr(CFMapMarkerLayerPrivate::create(this))
{
}

CFMapMarkerLayer::~CFMapMarkerLayer()
{
    delete d_ptr;
}

void CFMapMarkerLayer::setCoordinate(CFMapCoordinate *coordinate)
{
    Q_D(CFMapMarkerLayer);
    d->setCoordinate(coordinate);
}

CFMapCoordinate *CFMapMarkerLayer::coordinate() const
{
    Q_D(const CFMapMarkerLayer);
    return d->coordinate();
}

void CFMapMarkerLayer::setRotation(qreal rotation)
{
    Q_D(CFMapMarkerLayer);
    d->setRotation(rotation);
}

qreal CFMapMarkerLayer::rotation() const
{
    Q_D(const CFMapMarkerLayer);
    return d->rotation();
}

void CFMapMarkerLayer::setOpacity(qreal opacity)
{
    Q_D(CFMapMarkerLayer);
    d->setOpacity(opacity);
}

qreal CFMapMarkerLayer::opacity() const
{
    Q_D(const CFMapMarkerLayer);
    return d->opacity();
}

void *CFMapMarkerLayer::nativeObject() const
{
    Q_D(const CFMapMarkerLayer);
    return d->nativeObject();
}
