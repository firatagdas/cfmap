#include "cfmapmarkerlayer_android_p.h"

CFMapMarkerLayerPrivate *CFMapMarkerLayerPrivate::create(CFMapMarkerLayer *q)
{
    return new CFMapMarkerLayerAndroidPrivate(q);
}

CFMapMarkerLayerAndroidPrivate::CFMapMarkerLayerAndroidPrivate(CFMapMarkerLayer *q)
    : CFMapMarkerLayerPrivate(q)
{
}

CFMapMarkerLayerAndroidPrivate::~CFMapMarkerLayerAndroidPrivate()
{
}

void CFMapMarkerLayerAndroidPrivate::setLatitude(qreal latitude)
{
}

qreal CFMapMarkerLayerAndroidPrivate::latitude() const
{
    return 0.;
}

void CFMapMarkerLayerAndroidPrivate::setLongitude(qreal longitude)
{
}

qreal CFMapMarkerLayerAndroidPrivate::longitude() const
{
    return 0.;
}

void *CFMapMarkerLayerAndroidPrivate::nativeObject()
{
    return 0;
}
