#ifndef CFMAPVIEW_H
#define CFMAPVIEW_H

#include <QObject>
#include <QtWebView/private/qwindowcontrolleritem_p.h>
#include "cfmap_global.h"
#include <QLoggingCategory>
#include <QList>
#include <QQmlListProperty>

Q_DECLARE_LOGGING_CATEGORY(CFMapViewTag)

class CFMapViewPrivate;
class CFMapCameraPosition;
class CFMapCoordinate;
class CFMapMarker;

class Q_CFMAP_EXPORT CFMapView : public QWindowControllerItem
{
    Q_OBJECT
    Q_ENUMS(MapType)
    Q_PROPERTY(bool scrollGestures READ scrollGestures WRITE setScrollGestures NOTIFY scrollGesturesChanged)
    Q_PROPERTY(bool zoomGestures READ zoomGestures WRITE setZoomGestures NOTIFY zoomGesturesChanged)
    Q_PROPERTY(bool tiltGestures READ tiltGestures WRITE setTiltGestures NOTIFY tiltGesturesChanged)
    Q_PROPERTY(bool rotateGestures READ rotateGestures WRITE setRotateGestures NOTIFY rotateGesturesChanged)
    Q_PROPERTY(bool consumesGesturesInView READ consumesGesturesInView WRITE setConsumesGesturesInView NOTIFY consumesGesturesInViewChanged)
    Q_PROPERTY(bool compassButton READ compassButton WRITE setCompassButton NOTIFY compassButtonChanged)
    Q_PROPERTY(bool myLocationButton READ myLocationButton WRITE setMyLocationButton NOTIFY myLocationButtonChanged)
    Q_PROPERTY(bool indoorPicker READ indoorPicker WRITE setIndoorPicker NOTIFY indoorPickerChanged)
    Q_PROPERTY(MapType mapType READ mapType WRITE setMapType NOTIFY mapTypeChanged)
    Q_PROPERTY(QQmlListProperty<CFMapMarker> markers READ markers)

public:
    enum MapType {
        MapTypeNormal,
        MapTypeHyrib,
        MapTypeSatellite,
        MapTypeTerrain,
        MapTypeNone
    };

    CFMapView(QQuickItem *parent = 0);
    ~CFMapView();

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

    void setMapType(MapType mapType);
    MapType mapType() const;

    Q_INVOKABLE void clear();
    Q_INVOKABLE void setZoomRange(int min, int max);
    Q_INVOKABLE void animateToCameraPosition(CFMapCameraPosition *position);
    Q_INVOKABLE void animateToLocation(CFMapCoordinate *coordinate);
    Q_INVOKABLE void animateToZoom(qreal zoom);
    Q_INVOKABLE void animateToBearing(qreal bearing);
    Q_INVOKABLE void animateToViewingAngle(qreal viewingAngle);
    Q_INVOKABLE void animateWithCameraUpdateZoomIn();
    Q_INVOKABLE void animateWithCameraUpdateZoomOut();
    Q_INVOKABLE void animateWithCameraUpdateZoomBy(qreal delta);
    Q_INVOKABLE void animateWithCameraUpdateZoomTo(qreal zoom);
    Q_INVOKABLE void animateWithCameraUpdateSetTarget(CFMapCoordinate *target);
    Q_INVOKABLE void animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom);
    Q_INVOKABLE void animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition);

    Q_INVOKABLE void zoomBy(qreal zoom, const QPointF &point);
    Q_INVOKABLE void scrollBy(const QPointF &point);

    Q_INVOKABLE void addMarkerStatic(CFMapMarker *marker);
    Q_INVOKABLE void addMarker(CFMapMarker *marker);
    Q_INVOKABLE void removeMarker(CFMapMarker *marker);

    QQmlListProperty<CFMapMarker> markers();

    void *nativeObject();

private:
    static void appendMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list, CFMapMarker *marker);
    static int countMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list);
    static CFMapMarker *atMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list, int i);
    static void clearMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list);

Q_SIGNALS:
    void scrollGesturesChanged();
    void zoomGesturesChanged();
    void tiltGesturesChanged();
    void rotateGesturesChanged();
    void consumesGesturesInViewChanged();
    void compassButtonChanged();
    void myLocationButtonChanged();
    void indoorPickerChanged();
    void mapTypeChanged();

protected:
    void componentComplete() Q_DECL_OVERRIDE;

private:
    Q_DECLARE_PRIVATE(CFMapView)
    CFMapViewPrivate *d_ptr;
};

Q_DECLARE_METATYPE(CFMapView::MapType)

#endif // CFMAPVIEW_H
