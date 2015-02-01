#include "cfmapmarker_ios_p.h"
#include "cfmapmarker.h"
#include "../coordinate/cfmapcoordinate_ios_p.h"
#include "../markerlayer/cfmapmarkerlayer_ios_p.h"
#include <QJsonDocument>
#include <CFMvc/cfiosutil.h>
#include <QPointF>
#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>

CFMapMarkerPrivate *CFMapMarkerPrivate::create(CFMapMarker *q)
{
    return new CFMapMarkerIosPrivate(q);
}

CFMapMarkerIosPrivate::CFMapMarkerIosPrivate(CFMapMarker *q)
    : CFMapMarkerPrivate(q)
    , m_marker([[GMSMarker alloc] init])
    , m_coordinate(0)
    , m_markerLayer(0)
    , m_appearAnimationType(CFMapMarker::AppearAnimationPop)
{
}

CFMapMarkerIosPrivate::~CFMapMarkerIosPrivate()
{
    [m_marker release];
}

void CFMapMarkerIosPrivate::setCoordinate(CFMapCoordinate *coordinate)
{
    if (m_coordinate != coordinate) {
        if (m_coordinate) {
            m_coordinate->deleteLater();
            m_coordinate = 0;
        }

        m_coordinate = coordinate;
        m_marker.position = CLLocationCoordinate2DMake(m_coordinate->latitude(), m_coordinate->longitude());

        Q_EMIT q()->coordinateChanged();
    }
}

CFMapCoordinate *CFMapMarkerIosPrivate::coordinate() const
{
    return m_coordinate;
}

void CFMapMarkerIosPrivate::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        restoreMarker();
        q()->textChanged();
    }
}

QString CFMapMarkerIosPrivate::text() const
{
    return m_text;
}

void CFMapMarkerIosPrivate::setTitle(const QString &title)
{
    if (QString::fromNSString(m_marker.title) != title) {
        m_marker.title = [[NSString alloc] initWithFormat:@"%s", title.toUtf8().data()];
        Q_EMIT q()->titleChanged();
    }
}

QString CFMapMarkerIosPrivate::title() const
{
    return QString::fromNSString(m_marker.title);
}

void CFMapMarkerIosPrivate::setIcon(const QString &icon)
{
    if (m_icon != icon) {
        m_icon = icon;
        restoreMarker();
        Q_EMIT q()->iconChanged();
    }
}

QString CFMapMarkerIosPrivate::icon() const
{
    return m_icon;
}

void CFMapMarkerIosPrivate::setSnippet(const QString &snippet)
{
    if (QString::fromNSString(m_marker.snippet) != snippet) {
        m_marker.snippet = [[NSString alloc] initWithFormat:@"%s", snippet.toUtf8().data()];
        Q_EMIT q()->snippetChanged();
    }
}

QString CFMapMarkerIosPrivate::snippet() const
{
    return QString::fromNSString(m_marker.snippet);
}

void CFMapMarkerIosPrivate::setInfoWindowAnchor(const QPointF &point)
{
    if (m_marker.infoWindowAnchor.x != point.x() && m_marker.infoWindowAnchor.y != point.y()) {
        m_marker.infoWindowAnchor = CGPointMake(point.x(), point.y());

        Q_EMIT q()->infoWindowAnchorChanged();
    }
}

QPointF CFMapMarkerIosPrivate::infoWindowAnchor() const
{
    return QPointF(m_marker.infoWindowAnchor.x, m_marker.infoWindowAnchor.y);
}

void CFMapMarkerIosPrivate::setGroundAnchor(const QPointF &point)
{
    if (m_marker.groundAnchor.x != point.x() && m_marker.groundAnchor.y != point.y()) {
        m_marker.groundAnchor = CGPointMake(point.x(), point.y());

        Q_EMIT q()->groundAnchorChanged();
    }
}

QPointF CFMapMarkerIosPrivate::groundAnchor() const
{
    return QPointF(m_marker.groundAnchor.x, m_marker.groundAnchor.y);
}

void CFMapMarkerIosPrivate::setAnimationType(CFMapMarker::AppearAnimationType animationType)
{
    if (m_appearAnimationType != animationType) {
        m_appearAnimationType = animationType;

        GMSMarkerAnimation type = kGMSMarkerAnimationNone;
        switch (animationType) {
        case CFMapMarker::AppearAnimationNone:
            // already handled
            break;
        case CFMapMarker::AppearAnimationPop:
            type = kGMSMarkerAnimationPop;
            break;
        }

        m_marker.appearAnimation = type;
        Q_EMIT q()->animationTypeChanged();
    }
}

CFMapMarker::AppearAnimationType CFMapMarkerIosPrivate::animationType() const
{
    return m_appearAnimationType;
}

void CFMapMarkerIosPrivate::setDraggable(bool value)
{
    BOOL native = value ? YES : NO;
    if (m_marker.draggable != native) {
        m_marker.draggable = native;

        Q_EMIT q()->draggableChanged();
    }
}

bool CFMapMarkerIosPrivate::draggable() const
{
    return m_marker.draggable ? YES : NO;
}

void CFMapMarkerIosPrivate::setFlat(bool value)
{
    BOOL native = value ? YES : NO;
    if (m_marker.flat != native) {
        m_marker.flat = native;

        Q_EMIT q()->flatChanged();
    }
}

bool CFMapMarkerIosPrivate::flat() const
{
    return m_marker.flat ? YES : NO;
}

void CFMapMarkerIosPrivate::setRotation(qreal rotation)
{
    if (m_marker.rotation != rotation) {
        m_marker.rotation = rotation;

        Q_EMIT q()->rotationChanged();
    }
}

qreal CFMapMarkerIosPrivate::rotation() const
{
    return m_marker.rotation;
}

void CFMapMarkerIosPrivate::setOpacity(qreal opacity)
{
    if (m_marker.opacity != opacity) {
        m_marker.opacity = opacity;

        Q_EMIT q()->opacityChanged();
    }
}

qreal CFMapMarkerIosPrivate::opacity() const
{
    return m_marker.opacity;
}

void CFMapMarkerIosPrivate::setUserData(const QVariant &userData)
{
    if (m_userData != userData) {
        m_userData = userData;

        m_marker.userData = variantToDictionary(userData);
        Q_EMIT q()->userDataChanged();
    }
}

QVariant CFMapMarkerIosPrivate::userData() const
{
    return m_userData;
}

void CFMapMarkerIosPrivate::setLayer(CFMapMarkerLayer *layer)
{
    if (m_markerLayer != layer) {
        m_markerLayer = layer;

        GMSMarkerLayer *nativeLayer = id(layer->nativeObject());
        m_marker.layer.latitude = nativeLayer.latitude;
        m_marker.layer.longitude = nativeLayer.longitude;
        m_marker.layer.rotation = nativeLayer.rotation;
        m_marker.layer.opacity = nativeLayer.opacity;

        Q_EMIT q()->layerChanged();
    }
}

CFMapMarkerLayer *CFMapMarkerIosPrivate::layer() const
{
    return m_markerLayer;
}

void CFMapMarkerIosPrivate::setTappable(bool value)
{
    BOOL native = value ? YES : NO;
    if (m_marker.tappable != native) {
        m_marker.tappable = native;

        Q_EMIT q()->tappableChanged();
    }
}

bool CFMapMarkerIosPrivate::tappable() const
{
    return m_marker.tappable ? true : false;
}

void CFMapMarkerIosPrivate::setZIndex(int zIndex)
{
    if (m_marker.zIndex != zIndex) {
        m_marker.zIndex = zIndex;

        Q_EMIT q()->zIndexChanged();
    }
}

int CFMapMarkerIosPrivate::zIndex() const
{
    return m_marker.zIndex;
}

bool CFMapMarkerIosPrivate::active() const
{
    return (m_marker.map != nil);
}

void CFMapMarkerIosPrivate::removeFromMap()
{
    if (m_marker.map != nil) {
        m_marker.map = nil;
        Q_EMIT q()->activeChanged();
    }
}

void *CFMapMarkerIosPrivate::nativeObject() const
{
    return m_marker;
}

void CFMapMarkerIosPrivate::restoreMarker()
{
    if (m_icon.isEmpty())
        return;

    if (m_marker.icon != nil)
        [m_marker.icon release];

    NSString *iconName = [[NSString alloc] initWithFormat:@"%s", m_icon.toUtf8().data()];
    UIImage *icon = [UIImage imageNamed:iconName];

    if (!m_text.isEmpty()) {

        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, icon.size.width, icon.size.height)];
        UIImageView *markerView = [[UIImageView alloc] initWithImage:icon];
        NSString *markerText = [[NSString alloc] initWithFormat:@"%s", m_text.toUtf8().data()];

        UIFont *font = [UIFont fontWithName:@"HelveticaNeue" size:14];
        CGSize labelSize = [markerText sizeWithFont:font constrainedToSize:CGSizeMake(icon.size.width, 13.f) lineBreakMode:NSLineBreakByWordWrapping];

        UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake((icon.size.width - labelSize.width) / 2, 7.f, labelSize.width, labelSize.height)];
        label.text = markerText;
        label.font = font;
        label.clipsToBounds = YES;
        label.backgroundColor = [UIColor clearColor];
        label.textColor = [UIColor whiteColor];
        label.textAlignment = NSTextAlignmentLeft;
        label.lineBreakMode = NSLineBreakByWordWrapping;
        label.numberOfLines = 0;

        [view addSubview:markerView];
        [view addSubview:label];

        if ([[UIScreen mainScreen] respondsToSelector:@selector(scale)])
            UIGraphicsBeginImageContextWithOptions(view.frame.size, NO, [[UIScreen mainScreen] scale]);
        else
            UIGraphicsBeginImageContext(view.frame.size);

        [view.layer renderInContext: UIGraphicsGetCurrentContext()];
        icon = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
    }

    m_marker.icon = icon;
}
