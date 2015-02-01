#include "cfmapmarkerlayer_default_p.h"

CFMapMarkerLayerPrivate *CFMapMarkerLayerPrivate::create(CFMapCoordinate *q)
{
    return new CFMapMarkerLayerDefaultPrivate(q);
}

CFMapMarkerLayerDefaultPrivate::CFMapMarkerLayerDefaultPrivate(CFMapMarkerLayer *q)
    : CFMapMarkerLayerPrivate(q)
{
}

CFMapMarkerLayerDefaultPrivate::~CFMapMarkerLayerDefaultPrivate()
{
}

void CFMapMarkerLayerDefaultPrivate::setCoordinate(CFMapCoordinate *coordinate)
{

}

CFMapCoordinate *CFMapMarkerLayerDefaultPrivate::coordinate() const
{
    return 0;
}

void CFMapMarkerLayerDefaultPrivate::setRotation(qreal rotation)
{

}

qreal CFMapMarkerLayerDefaultPrivate::rotation() const
{
    return 0;
}

void CFMapMarkerLayerDefaultPrivate::setOpacity(qreal opacity)
{

}

qreal CFMapMarkerLayerDefaultPrivate::opacity() const
{
    return 0;
}

void *CFMapMarkerLayerDefaultPrivate::nativeObject() const
{
    return 0;
}
