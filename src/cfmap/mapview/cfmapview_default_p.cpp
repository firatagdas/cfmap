#include "cfmapview_default_p.h"


CFMapViewPrivate *CFMapViewPrivate::create(CFMapView *q)
{
    return new CFMapViewDefaultPrivate(q);
}

CFMapViewDefaultPrivate::CFMapViewDefaultPrivate(CFMapView *q)
    : CFMapViewPrivate(q)
{
}

CFMapViewDefaultPrivate::~CFMapViewDefaultPrivate()
{
}

void *CFMapViewDefaultPrivate::nativeView()
{
    return 0;
}


void CFMapViewDefaultPrivate::setScrollGestures(bool value)
{

}

bool CFMapViewDefaultPrivate::scrollGestures() const
{

}

void CFMapViewDefaultPrivate::setZoomGestures(bool value)
{

}

bool CFMapViewDefaultPrivate::zoomGestures() const
{

}

void CFMapViewDefaultPrivate::setTiltGestures(bool value)
{

}

bool CFMapViewDefaultPrivate::tiltGestures() const
{

}

void CFMapViewDefaultPrivate::setRotateGestures(bool value)
{

}

bool CFMapViewDefaultPrivate::rotateGestures() const
{

}

void CFMapViewDefaultPrivate::setConsumesGesturesInView(bool value)
{

}

bool CFMapViewDefaultPrivate::consumesGesturesInView() const
{

}

void CFMapViewDefaultPrivate::setCompassButton(bool value)
{

}

bool CFMapViewDefaultPrivate::compassButton() const
{

}

void CFMapViewDefaultPrivate::setMyLocationButton(bool value)
{

}

bool CFMapViewDefaultPrivate::myLocationButton() const
{

}

void CFMapViewDefaultPrivate::setIndoorPicker(bool value)
{

}

bool CFMapViewDefaultPrivate::indoorPicker() const
{

}

void CFMapViewDefaultPrivate::setMapType(int mapType)
{

}

int CFMapViewDefaultPrivate::mapType() const
{

}

void CFMapViewDefaultPrivate::clear()
{

}

void CFMapViewDefaultPrivate::setZoomRange(int min, int max)
{

}

void CFMapViewDefaultPrivate::animateToCameraPosition(CFMapCameraPosition *position)
{

}

void CFMapViewDefaultPrivate::animateToLocation(CFMapCoordinate *coordinate)
{

}

void CFMapViewDefaultPrivate::animateToZoom(qreal zoom)
{

}

void CFMapViewDefaultPrivate::animateToBearing(qreal bearing)
{

}

void CFMapViewDefaultPrivate::animateToViewingAngle(qreal viewingAngle)
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateZoomIn()
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateZoomOut()
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateZoomBy(qreal delta)
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateZoomTo(qreal zoom)
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target)
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom)
{

}

void CFMapViewDefaultPrivate::animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition)
{

}

