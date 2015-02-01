#include "cfmapview.h"
#include "cfmapview_p.h"
#include "../marker/cfmapmarker.h"

Q_LOGGING_CATEGORY(CFMapViewTag, "[CFMapView]")

CFMapView::CFMapView(QQuickItem *parent)
    : QWindowControllerItem(parent)
    , d_ptr(CFMapViewPrivate::create(this))
{
    WId id(WId(d_ptr->nativeView()));
    if (id != 0)
        setNativeWindow(id);
    else
        qWarning() << "No native view. Missing platform support?";
}

CFMapView::~CFMapView()
{
    delete d_ptr;
}

void CFMapView::setScrollGestures(bool value)
{
    Q_D(CFMapView);
    d->setScrollGestures(value);
}

bool CFMapView::scrollGestures() const
{
    Q_D(const CFMapView);
    return d->scrollGestures();
}

void CFMapView::setZoomGestures(bool value)
{
    Q_D(CFMapView);
    d->setZoomGestures(value);
}

bool CFMapView::zoomGestures() const
{
    Q_D(const CFMapView);
    return d->zoomGestures();
}

void CFMapView::setTiltGestures(bool value)
{
    Q_D(CFMapView);
    d->setTiltGestures(value);
}

bool CFMapView::tiltGestures() const
{
    Q_D(const CFMapView);
    return d->tiltGestures();
}

void CFMapView::setRotateGestures(bool value)
{
    Q_D(CFMapView);
    d->setRotateGestures(value);
}

bool CFMapView::rotateGestures() const
{
    Q_D(const CFMapView);
    return d->rotateGestures();
}

void CFMapView::setConsumesGesturesInView(bool value)
{
    Q_D(CFMapView);
    d->setConsumesGesturesInView(value);
}

bool CFMapView::consumesGesturesInView() const
{
    Q_D(const CFMapView);
    return d->consumesGesturesInView();
}

void CFMapView::setCompassButton(bool value)
{
    Q_D(CFMapView);
    d->setCompassButton(value);
}

bool CFMapView::compassButton() const
{
    Q_D(const CFMapView);
    return d->compassButton();
}

void CFMapView::setMyLocationButton(bool value)
{
    Q_D(CFMapView);
    d->setMyLocationButton(value);
}

bool CFMapView::myLocationButton() const
{
    Q_D(const CFMapView);
    return d->myLocationButton();
}

void CFMapView::setIndoorPicker(bool value)
{
    Q_D(CFMapView);
    d->setIndoorPicker(value);
}

bool CFMapView::indoorPicker() const
{
    Q_D(const CFMapView);
    return d->indoorPicker();
}

void CFMapView::setMapType(CFMapView::MapType mapType)
{
    Q_D(CFMapView);
    d->setMapType(mapType);
}

CFMapView::MapType CFMapView::mapType() const
{
    Q_D(const CFMapView);
    return d->mapType();
}

void CFMapView::clear()
{
    Q_D(CFMapView);
    int i = 0;
    int len = d->m_markers.count();
    for (; i < len; i++)
        d->m_markers.at(i)->removeFromMap();

    d->clear();
}

void CFMapView::setZoomRange(int min, int max)
{
    Q_D(CFMapView);
    d->setZoomRange(min, max);
}

void CFMapView::animateToCameraPosition(CFMapCameraPosition *position)
{
    Q_D(CFMapView);
    d->animateToCameraPosition(position);
}

void CFMapView::animateToLocation(CFMapCoordinate *coordinate)
{
    Q_D(CFMapView);
    d->animateToLocation(coordinate);
}

void CFMapView::animateToZoom(qreal zoom)
{
    Q_D(CFMapView);
    d->animateToZoom(zoom);
}

void CFMapView::animateToBearing(qreal bearing)
{
    Q_D(CFMapView);
    d->animateToBearing(bearing);
}

void CFMapView::animateToViewingAngle(qreal viewingAngle)
{
    Q_D(CFMapView);
    d->animateToViewingAngle(viewingAngle);
}

void CFMapView::animateWithCameraUpdateZoomIn()
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateZoomIn();
}

void CFMapView::animateWithCameraUpdateZoomOut()
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateZoomOut();
}

void CFMapView::animateWithCameraUpdateZoomBy(qreal delta)
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateZoomBy(delta);
}

void CFMapView::animateWithCameraUpdateZoomTo(qreal zoom)
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateZoomTo(zoom);
}

void CFMapView::animateWithCameraUpdateSetTarget(CFMapCoordinate *target)
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateSetTarget(target);
}

void CFMapView::animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom)
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateSetTarget(target, zoom);
}

void CFMapView::animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition)
{
    Q_D(CFMapView);
    d->animateWithCameraUpdateSetCamera(cameraPosition);
}

void CFMapView::zoomBy(qreal zoom, const QPointF &point)
{
    Q_D(CFMapView);
    d->zoomBy(zoom, point);
}

void CFMapView::scrollBy(const QPointF &point)
{
    Q_D(CFMapView);
    d->scrollBy(point);
}

void CFMapView::componentComplete()
{
    QWindowControllerItem::componentComplete();
}

void CFMapView::addMarkerStatic(CFMapMarker *marker)
{
    addMarker(marker);
    marker->setParent(this);
}

void CFMapView::addMarker(CFMapMarker *marker)
{
    Q_D(CFMapView);
    if (d->addMarker(marker))
        marker->setParent(this);
}

void CFMapView::removeMarker(CFMapMarker *marker)
{
    Q_D(CFMapView);
    if (d->removeMarker(marker)) {
        CFMapView *parent = qobject_cast<CFMapView *>(marker->parent());
        if (parent != 0 && parent == this)
            marker->deleteLater();
    }
}

QQmlListProperty<CFMapMarker> CFMapView::markers()
{
    return QQmlListProperty<CFMapMarker>(this, 0, &CFMapView::appendMarkerQtIntegration, &CFMapView::countMarkerQtIntegration, &CFMapView::atMarkerQtIntegration, &CFMapView::clearMarkerQtIntegration);
}

void CFMapView::appendMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list, CFMapMarker *marker)
{
    CFMapView *mapView = qobject_cast<CFMapView *>(list->object);
    if (mapView)
        mapView->addMarkerStatic(marker);
}

int CFMapView::countMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list)
{
    CFMapView *mapView = qobject_cast<CFMapView *>(list->object);
    if (!mapView)
        return 0;

    return mapView->d_ptr->m_markers.count();
}

CFMapMarker *CFMapView::atMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list, int i)
{
    CFMapView *mapView = qobject_cast<CFMapView *>(list->object);
    if (!mapView)
        return 0;

    return mapView->d_ptr->m_markers.at(i);
}

void CFMapView::clearMarkerQtIntegration(QQmlListProperty<CFMapMarker> *list)
{
    CFMapView *mapView = qobject_cast<CFMapView *>(list->object);
    if (mapView)
        return mapView->clear();
}

void *CFMapView::nativeObject()
{
    Q_D(CFMapView);
    return (void *) d->nativeView();
}
