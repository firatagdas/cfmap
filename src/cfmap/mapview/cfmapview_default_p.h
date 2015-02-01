#ifndef CFMAPVIEW_DEFAULT_P_H
#define CFMAPVIEW_DEFAULT_P_H

#include "cfmapview_p.h"

class CFMapViewDefaultPrivate : public CFMapViewPrivate
{
    Q_OBJECT
public:
    explicit CFMapViewDefaultPrivate(CFMapView *q);
    virtual ~CFMapViewDefaultPrivate();

    void *nativeView();

    void setScrollGestures(bool value);
    bool scrollGestures() const;

    void setZoomGestures(bool value);
    bool zoomGestures() const;

    void setTiltGestures(bool value);
    bool tiltGestures() const;

    void setRotateGestures(bool value);
    bool rotateGestures() const;

    void setConsumesGesturesInView(bool value);
    bool consumesGesturesInView() const;

    void setCompassButton(bool value);
    bool compassButton() const;

    void setMyLocationButton(bool value);
    bool myLocationButton() const;

    void setIndoorPicker(bool value);
    bool indoorPicker() const;

    void setMapType(int mapType);
    int mapType() const;

    void clear();
    void setZoomRange(int min, int max);

    void moveCameraZoomIn();
    void moveCameraZoomOut();
    void moveCameraZoomBy(qreal delta);
    void moveCameraZoomTo(qreal zoom);
    void moveCameraSetTarget(CFMapCoordinate *target);
    void moveCameraSetTarget(CFMapCoordinate *target, qreal zoom);
    void moveCameraSetCamera(CFMapCameraPosition *cameraPosition);

    void animateToCameraPosition(CFMapCameraPosition *position);
    void animateToLocation(CFMapCoordinate *coordinate);
    void animateToZoom(qreal zoom);
    void animateToBearing(qreal bearing);
    void animateToViewingAngle(qreal viewingAngle);
    void animateWithCameraUpdateZoomIn();
    void animateWithCameraUpdateZoomOut();
    void animateWithCameraUpdateZoomBy(qreal delta);
    void animateWithCameraUpdateZoomTo(qreal zoom);
    void animateWithCameraUpdateSetTarget(CFMapCoordinate *target);
    void animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom);
    void animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition);

    bool addMarker(CFMapMarker *marker);
    bool removeMarker(CFMapMarker *marker);
};

#endif
