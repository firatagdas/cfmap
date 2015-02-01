#ifndef CFMAPVIEW_IOS_P_H
#define CFMAPVIEW_IOS_P_H

#include "cfmapview_p.h"
#include "cfmapview.h"

Q_FORWARD_DECLARE_OBJC_CLASS(GMSMapView);

class CFMapViewIosPrivate : public CFMapViewPrivate
{
    Q_OBJECT
public:
    explicit CFMapViewIosPrivate(CFMapView *q);
    virtual ~CFMapViewIosPrivate();

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

    void setMapType(CFMapView::MapType mapType);
    CFMapView::MapType mapType() const;

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
    void zoomBy(qreal zoom, const QPointF &point);
    void scrollBy(const QPointF &point);

    bool addMarker(CFMapMarker *marker);
    bool removeMarker(CFMapMarker *marker);

private:
    GMSMapView *m_mapView;
    void *m_delegate;
};

#endif // CFMAPVIEW_IOS_P_H
