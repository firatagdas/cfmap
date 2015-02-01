#include "cfmapview_ios_p.h"
#include <QDebug>
#include "../coordinate/cfmapcoordinate.h"
#include "../cameraposition/cfmapcameraposition.h"
#include "../marker/cfmapmarker.h"
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <GoogleMaps/GoogleMaps.h>

@interface CFMapViewDelegate : NSObject<GMSMapViewDelegate>
{
}
@end

@implementation CFMapViewDelegate

- (void)mapView:(GMSMapView *)mapView didTapAtCoordinate:(CLLocationCoordinate2D)coordinate
{
    /*GMSCameraPosition *camera = [GMSCameraPosition cameraWithTarget:coordinate zoom:14];
    [mapView animateToCameraPosition:camera];
    GMSMarker *marker = [GMSMarker markerWithPosition:coordinate];
    marker.title = @"Lorem Ipsum is simply dummy text of the printing and typesetting industry.  Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book";
    marker.map = mapView;*/
    qCDebug(CFMapViewTag) << "Map Tap Coordinates" << coordinate.latitude << coordinate.longitude;
}

- (UIView *)mapView:(GMSMapView *)mapView markerInfoWindow:(GMSMarker *)marker
{
    Q_UNUSED(mapView)

    UIFont *font = [UIFont fontWithName:@"HelveticaNeue" size:12];
    NSString *text = marker.title;
    CGSize labelSize = [text sizeWithFont:font constrainedToSize:CGSizeMake(250.f, 60.f) lineBreakMode:NSLineBreakByWordWrapping];

    UIImage *bubleLeft = [UIImage imageNamed:@"CFMapInfoResource.bundle/buble-left.png"];
    bubleLeft = [bubleLeft resizableImageWithCapInsets:UIEdgeInsetsMake(12, 8, 12, 8) resizingMode:UIImageResizingModeTile];
    UIImageView *bubleLeftView = [[UIImageView alloc] initWithImage:bubleLeft];
    bubleLeftView.clipsToBounds = NO;
    bubleLeftView.layer.masksToBounds = NO;

    UIImage *bubleRight = [UIImage imageNamed:@"CFMapInfoResource.bundle/buble-right.png"];
    bubleRight = [bubleRight resizableImageWithCapInsets:UIEdgeInsetsMake(12, 8, 12, 8) resizingMode:UIImageResizingModeTile];
    UIImageView *bubleRightView = [[UIImageView alloc] initWithImage:bubleRight];
    bubleRightView.clipsToBounds = NO;
    bubleRightView.layer.masksToBounds = NO;

    CGFloat popupWidth = labelSize.width + 30.f;
    CGFloat popupHeight = qMax<CGFloat>(bubleRightView.frame.size.height, labelSize.height + 30.f);

    bubleLeftView.frame = CGRectMake(0.f, 0.f, floor(popupWidth * 0.5f), popupHeight);
    bubleRightView.frame = CGRectMake(bubleLeftView.frame.size.width, 0.f, popupWidth * 0.5f, popupHeight);

    UIView *parentView = [[UIView alloc] initWithFrame:CGRectMake(0.f, 0.f, popupWidth, popupHeight)];
    [parentView addSubview:bubleLeftView];
    [parentView addSubview:bubleRightView];

    UILabel *fromLabel = [[UILabel alloc] initWithFrame:CGRectMake((popupWidth - labelSize.width) / 2, (popupHeight - labelSize.height - 6) / 2, labelSize.width, labelSize.height)];
    fromLabel.text = text;
    fromLabel.font = font;
    fromLabel.clipsToBounds = YES;
    fromLabel.backgroundColor = [UIColor clearColor];
    fromLabel.textColor = [UIColor whiteColor];
    fromLabel.textAlignment = NSTextAlignmentLeft;
    fromLabel.lineBreakMode = NSLineBreakByWordWrapping;
    fromLabel.numberOfLines = 0;

    [parentView addSubview:fromLabel];

    return parentView;
}

@end

CFMapViewPrivate *CFMapViewPrivate::create(CFMapView *q)
{
    return new CFMapViewIosPrivate(q);
}

CFMapViewIosPrivate::CFMapViewIosPrivate(CFMapView *q)
    : CFMapViewPrivate(q)
{
    CGRect frame = CGRectMake(0.0, 0.0, 400, 400);
    m_mapView = [[GMSMapView alloc] initWithFrame:frame];

    CFMapViewDelegate *delegate = [[CFMapViewDelegate alloc] init];
    m_mapView.delegate = delegate;
    m_mapView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    m_delegate = (void *) delegate;
}

CFMapViewIosPrivate::~CFMapViewIosPrivate()
{
    [m_mapView release];
}

void *CFMapViewIosPrivate::nativeView()
{
    return (void *) m_mapView;
}

void CFMapViewIosPrivate::setScrollGestures(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.scrollGestures) {
        m_mapView.settings.scrollGestures = nativeBool;
        Q_EMIT q->scrollGesturesChanged();
    }
}

bool CFMapViewIosPrivate::scrollGestures() const
{
    return m_mapView.settings.scrollGestures ? true : false;
}

void CFMapViewIosPrivate::setZoomGestures(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.zoomGestures) {
        m_mapView.settings.zoomGestures = nativeBool;
        Q_EMIT q->zoomGesturesChanged();
    }
}

bool CFMapViewIosPrivate::zoomGestures() const
{
    return m_mapView.settings.zoomGestures ? true : false;
}

void CFMapViewIosPrivate::setTiltGestures(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.tiltGestures) {
        m_mapView.settings.tiltGestures = nativeBool;
        Q_EMIT q->tiltGesturesChanged();
    }
}

bool CFMapViewIosPrivate::tiltGestures() const
{
    return m_mapView.settings.tiltGestures ? true : false;
}

void CFMapViewIosPrivate::setRotateGestures(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.rotateGestures) {
        m_mapView.settings.rotateGestures = nativeBool;
        Q_EMIT q->rotateGesturesChanged();
    }
}

bool CFMapViewIosPrivate::rotateGestures() const
{
    return m_mapView.settings.rotateGestures ? true : false;
}

void CFMapViewIosPrivate::setConsumesGesturesInView(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.consumesGesturesInView) {
        m_mapView.settings.consumesGesturesInView = nativeBool;
        Q_EMIT q->consumesGesturesInViewChanged();
    }
}

bool CFMapViewIosPrivate::consumesGesturesInView() const
{
    return m_mapView.settings.consumesGesturesInView ? true : false;
}

void CFMapViewIosPrivate::setCompassButton(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.compassButton) {
        m_mapView.settings.compassButton = nativeBool;
        Q_EMIT q->compassButtonChanged();
    }
}

bool CFMapViewIosPrivate::compassButton() const
{
    return m_mapView.settings.compassButton ? true : false;
}

void CFMapViewIosPrivate::setMyLocationButton(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.myLocationButton) {
        m_mapView.settings.myLocationButton = nativeBool;
        Q_EMIT q->myLocationButtonChanged();
    }
}

bool CFMapViewIosPrivate::myLocationButton() const
{
    return m_mapView.settings.myLocationButton ? true : false;
}

void CFMapViewIosPrivate::setIndoorPicker(bool value)
{
    Q_Q(CFMapView);

    BOOL nativeBool = value ? YES : NO;
    if (nativeBool != m_mapView.settings.indoorPicker) {
        m_mapView.settings.indoorPicker = nativeBool;
        Q_EMIT q->indoorPickerChanged();
    }
}

bool CFMapViewIosPrivate::indoorPicker() const
{
    return m_mapView.settings.indoorPicker ? true : false;
}

void CFMapViewIosPrivate::setMapType(CFMapView::MapType mapType)
{
    GMSMapViewType type = kGMSTypeNormal;
    switch (mapType) {
    case CFMapView::MapTypeNormal:
        // already handled
        break;
    case CFMapView::MapTypeHyrib:
        type = kGMSTypeHybrid;
        break;
    case CFMapView::MapTypeSatellite:
        type = kGMSTypeSatellite;
        break;
    case CFMapView::MapTypeTerrain:
        type = kGMSTypeTerrain;
        break;
    case CFMapView::MapTypeNone:
        type = kGMSTypeNone;
        break;
    }

    Q_Q(CFMapView);
    if (type != m_mapView.mapType) {
        m_mapView.mapType = type;
        Q_EMIT q->mapTypeChanged();
    }
}

CFMapView::MapType CFMapViewIosPrivate::mapType() const
{
    CFMapView::MapType type = CFMapView::MapTypeNormal;
    switch (m_mapView.mapType) {
    case kGMSTypeNormal:
        // already handled
        break;
    case kGMSTypeHybrid:
        type = CFMapView::MapTypeHyrib;
        break;
    case kGMSTypeSatellite:
        type = CFMapView::MapTypeSatellite;
        break;
    case kGMSTypeTerrain:
        type = CFMapView::MapTypeTerrain;
        break;
    case kGMSTypeNone:
        type = CFMapView::MapTypeNone;
        break;
    }

    return type;
}

void CFMapViewIosPrivate::clear()
{
    [m_mapView clear];
}

void CFMapViewIosPrivate::setZoomRange(int min, int max)
{
    [m_mapView setMinZoom:min maxZoom:max];
}

void CFMapViewIosPrivate::moveCameraZoomIn()
{
    [m_mapView moveCamera:[GMSCameraUpdate zoomIn]];
}

void CFMapViewIosPrivate::moveCameraZoomOut()
{
    [m_mapView moveCamera:[GMSCameraUpdate zoomOut]];
}

void CFMapViewIosPrivate::moveCameraZoomBy(qreal delta)
{
    [m_mapView moveCamera:[GMSCameraUpdate zoomBy:delta]];
}

void CFMapViewIosPrivate::moveCameraZoomTo(qreal zoom)
{
    [m_mapView moveCamera:[GMSCameraUpdate zoomTo:zoom]];
}

void CFMapViewIosPrivate::moveCameraSetTarget(CFMapCoordinate *target)
{
    [m_mapView moveCamera:[GMSCameraUpdate setTarget:CLLocationCoordinate2DMake(target->latitude(), target->longitude())]];
}

void CFMapViewIosPrivate::moveCameraSetTarget(CFMapCoordinate *target, qreal zoom)
{
    [m_mapView moveCamera:[GMSCameraUpdate setTarget:CLLocationCoordinate2DMake(target->latitude(), target->longitude()) zoom:zoom]];
}

void CFMapViewIosPrivate::moveCameraSetCamera(CFMapCameraPosition *cameraPosition)
{
    GMSCameraPosition *position = id(cameraPosition->nativeObject());
    [m_mapView moveCamera:[GMSCameraUpdate setCamera:position]];
}

void CFMapViewIosPrivate::animateToCameraPosition(CFMapCameraPosition *position)
{
    [m_mapView animateToCameraPosition:id(position->nativeObject())];
}

void CFMapViewIosPrivate::animateToLocation(CFMapCoordinate *coordinate)
{
    [m_mapView animateToLocation:CLLocationCoordinate2DMake(coordinate->latitude(), coordinate->longitude())];
}

void CFMapViewIosPrivate::animateToZoom(qreal zoom)
{
    [m_mapView animateToZoom:zoom];
}

void CFMapViewIosPrivate::animateToBearing(qreal bearing)
{
    [m_mapView animateToBearing:bearing];
}

void CFMapViewIosPrivate::animateToViewingAngle(qreal viewingAngle)
{
    [m_mapView animateToViewingAngle:viewingAngle];
}

void CFMapViewIosPrivate::animateWithCameraUpdateZoomIn()
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate zoomIn]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateZoomOut()
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate zoomOut]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateZoomBy(qreal delta)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate zoomBy:delta]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateZoomTo(qreal zoom)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate zoomTo:zoom]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate setTarget:CLLocationCoordinate2DMake(target->latitude(), target->longitude())]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateSetTarget(CFMapCoordinate *target, qreal zoom)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate setTarget:CLLocationCoordinate2DMake(target->latitude(), target->longitude()) zoom:zoom]];
}

void CFMapViewIosPrivate::animateWithCameraUpdateSetCamera(CFMapCameraPosition *cameraPosition)
{
    GMSCameraPosition *position = id(cameraPosition->nativeObject());
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate setCamera:position]];
}

void CFMapViewIosPrivate::zoomBy(qreal zoom, const QPointF &point)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate zoomBy:zoom atPoint:CGPointMake(point.x(), point.y())]];
}

void CFMapViewIosPrivate::scrollBy(const QPointF &point)
{
    [m_mapView animateWithCameraUpdate:[GMSCameraUpdate scrollByX:point.x() Y:point.y()]];
}

bool CFMapViewIosPrivate::addMarker(CFMapMarker *marker)
{
    if (m_markers.contains(marker))
        return false;

    GMSMarker *nativeMarker = id(marker->nativeObject());
    nativeMarker.map = m_mapView;

    m_markers.append(marker);
    return true;
}

bool CFMapViewIosPrivate::removeMarker(CFMapMarker *marker)
{
    if (!m_markers.contains(marker))
        return false;

    GMSMarker *nativeMarker = id(marker->nativeObject());
    nativeMarker.map = nil;

    int i = 0;
    int len = m_markers.count();
    for (; i < len; i++) {
        if (m_markers.at(i) == marker) {
            m_markers.removeAt(i);
            break;
        }
    }

    return true;
}

