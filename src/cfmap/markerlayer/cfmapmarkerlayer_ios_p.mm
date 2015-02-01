#include "cfmapmarkerlayer_ios_p.h"
#include "cfmapmarkerlayer.h"
#include "../coordinate/cfmapcoordinate_ios_p.h"
#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>

CFMapMarkerLayerPrivate *CFMapMarkerLayerPrivate::create(CFMapMarkerLayer *q)
{
    return new CFMapMarkerLayerIosPrivate(q);
}

CFMapMarkerLayerIosPrivate::CFMapMarkerLayerIosPrivate(CFMapMarkerLayer *q)
    : CFMapMarkerLayerPrivate(q)
    , m_markerLayer([[GMSMarkerLayer alloc] init])
    , m_coordinate(new CFMapCoordinate())
{
}

CFMapMarkerLayerIosPrivate::~CFMapMarkerLayerIosPrivate()
{
    [m_markerLayer release];
}

void CFMapMarkerLayerIosPrivate::setCoordinate(CFMapCoordinate *coordinate)
{
    if (m_coordinate != coordinate) {
        m_coordinate->deleteLater();
        m_coordinate = 0;

        m_coordinate = coordinate;
        m_markerLayer.latitude = m_coordinate->latitude();
        m_markerLayer.longitude = m_coordinate->longitude();

        Q_EMIT q()->coordinateChanged();

    }
}

CFMapCoordinate *CFMapMarkerLayerIosPrivate::coordinate() const
{
    return m_coordinate;
}

void CFMapMarkerLayerIosPrivate::setRotation(qreal rotation)
{
    if (m_markerLayer.rotation != rotation) {
        m_markerLayer.rotation = rotation;
        Q_EMIT q()->rotationChanged();
    }
}

qreal CFMapMarkerLayerIosPrivate::rotation() const
{
    return m_markerLayer.rotation;
}

void CFMapMarkerLayerIosPrivate::setOpacity(qreal opacity)
{
    if (m_markerLayer.opacity != opacity) {
        m_markerLayer.opacity = opacity;
        Q_EMIT q()->opacityChanged();
    }
}

qreal CFMapMarkerLayerIosPrivate::opacity() const
{
    return m_markerLayer.opacity;
}

void *CFMapMarkerLayerIosPrivate::nativeObject() const
{
    return (void *) m_markerLayer;
}
