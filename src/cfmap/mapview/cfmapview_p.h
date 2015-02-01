#ifndef CFMAPVIEW_P
#define CFMAPVIEW_P

#include <QObject>
#include "cfmapview.h"

class CFMapViewPrivate : public QObject
{
    Q_OBJECT
public:
    explicit CFMapViewPrivate(CFMapView *q)
        : QObject(0)
        , q_ptr(q)
    {}
    virtual ~CFMapViewPrivate() {}
    static CFMapViewPrivate *create(CFMapView *q);
    CFMapView *q() { return q_ptr; }

    virtual void *nativeView() = 0;

    virtual void setScrollGestures(bool value) = 0;
    virtual bool scrollGestures() const = 0;

    virtual void setZoomGestures(bool value) = 0;
    virtual bool zoomGestures() const = 0;

    virtual void setTiltGestures(bool value) = 0;
    virtual bool tiltGestures() const = 0;

    virtual void setRotateGestures(bool value) = 0;
    virtual bool rotateGestures() const = 0;

    virtual void setConsumesGesturesInView(bool value) = 0;
    virtual bool consumesGesturesInView() const = 0;

    virtual void setCompassButton(bool value) = 0;
    virtual bool compassButton() const = 0;

    virtual void setMyLocationButton(bool value) = 0;
    virtual bool myLocationButton() const = 0;

    virtual void setIndoorPicker(bool value) = 0;
    virtual bool indoorPicker() const = 0;

    virtual void setMapType(CFMapView::MapType mapType) = 0;
    virtual CFMapView::MapType mapType() const = 0;

    virtual void clear() = 0;
    virtual void setZoomRange(int min, int max) = 0;

    virtual void moveCameraZoomIn() = 0;
    virtual void moveCameraZoomOut() = 0;
    virtual void moveCameraZoomBy(qreal delta) = 0;
    virtual void moveCameraZoomTo(qreal zoom) = 0;
    virtual void moveCameraSetTarget(CFMapCoordinate *target) = 0;
    virtual void moveCameraSetTarget(CFMapCoordinate *target, qreal zoom) = 0;
    virtual void moveCameraSetCamera(CFMapCameraPosition *cameraPosition) = 0;

    virtual void animateToCameraPosition(CFMapCameraPosition *position) = 0;
    virtual void animateToLocation(CFMapCoordinate *coordinate) = 0;
    virtual void animateToZoom(qreal zoom) = 0;
    virtual void animateToBearing(qreal bearing) = 0;
    virtual void animateToViewingAngle(qreal viewingAngle) = 0;
    virtual void animateWithCameraUpdateZoomIn() = 0;
    virtual void animateWithCameraUpdateZoomOut() = 0;
    virtual void animateWithCameraUpdateZoomBy(qreal delta) = 0;
    virtual void animateWithCameraUpdateZoomTo(qreal zoom) = 0;
    virtual void animateWithCameraUpdateSetTarget(CFMapCoordinate *target) = 0;
    virtual void animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom) = 0;
    virtual void animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition) = 0;
    virtual void zoomBy(qreal zoom, const QPointF &point) = 0;
    virtual void scrollBy(const QPointF &point) = 0;

    virtual bool addMarker(CFMapMarker *marker) = 0;
    virtual bool removeMarker(CFMapMarker *marker) = 0;

protected:
    Q_DECLARE_PUBLIC(CFMapView)
    CFMapView *q_ptr;
    QList<CFMapMarker *> m_markers;
};

#endif // CFMAPVIEW_P

