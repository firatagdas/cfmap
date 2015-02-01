#include "cfmapmarker.h"
#include "cfmapmarker_p.h"
#include <QPointF>

CFMapMarker::CFMapMarker(QObject *parent)
    : QObject(parent)
    , d_ptr(CFMapMarkerPrivate::create(this))
{
}

CFMapMarker::~CFMapMarker()
{
    delete d_ptr;
}

void CFMapMarker::setText(const QString &text)
{
    Q_D(CFMapMarker);
    d->setText(text);
}

QString CFMapMarker::text() const
{
    Q_D(const CFMapMarker);
    return d->text();
}

void CFMapMarker::setCoordinate(CFMapCoordinate *coordinate)
{
    Q_D(CFMapMarker);
    d->setCoordinate(coordinate);
}

CFMapCoordinate *CFMapMarker::coordinate() const
{
    Q_D(const CFMapMarker);
    return d->coordinate();
}

void CFMapMarker::setTitle(const QString &title)
{
    Q_D(CFMapMarker);
    d->setTitle(title);
}

QString CFMapMarker::title() const
{
    Q_D(const CFMapMarker);
    return d->title();
}

void CFMapMarker::setIcon(const QString &icon)
{
    Q_D(CFMapMarker);
    d->setIcon(icon);
}

QString CFMapMarker::icon() const
{
    Q_D(const CFMapMarker);
    return d->icon();
}

void CFMapMarker::setSnippet(const QString &snippet)
{
    Q_D(CFMapMarker);
    d->setSnippet(snippet);
}

QString CFMapMarker::snippet() const
{
    Q_D(const CFMapMarker);
    return d->snippet();
}

void CFMapMarker::setInfoWindowAnchor(const QPointF &point)
{
    Q_D(CFMapMarker);
    d->setInfoWindowAnchor(point);
}

QPointF CFMapMarker::infoWindowAnchor() const
{
    Q_D(const CFMapMarker);
    return d->infoWindowAnchor();
}

void CFMapMarker::setGroundAnchor(const QPointF &point)
{
    Q_D(CFMapMarker);
    d->setGroundAnchor(point);
}

QPointF CFMapMarker::groundAnchor() const
{
    Q_D(const CFMapMarker);
    return d->groundAnchor();
}

void CFMapMarker::setAnimationType(CFMapMarker::AppearAnimationType animationType)
{
    Q_D(CFMapMarker);
    d->setAnimationType(animationType);
}

CFMapMarker::AppearAnimationType CFMapMarker::animationType() const
{
    Q_D(const CFMapMarker);
    return d->animationType();
}

void CFMapMarker::setDraggable(bool value)
{
    Q_D(CFMapMarker);
    d->setDraggable(value);
}

bool CFMapMarker::draggable() const
{
    Q_D(const CFMapMarker);
    return d->draggable();
}

void CFMapMarker::setFlat(bool value)
{
    Q_D(CFMapMarker);
    d->setFlat(value);
}

bool CFMapMarker::flat() const
{
    Q_D(const CFMapMarker);
    return d->flat();
}

void CFMapMarker::setRotation(qreal rotation)
{
    Q_D(CFMapMarker);
    d->setRotation(rotation);
}

qreal CFMapMarker::rotation() const
{
    Q_D(const CFMapMarker);
    return d->rotation();
}

void CFMapMarker::setOpacity(qreal opacity)
{
    Q_D(CFMapMarker);
    d->setOpacity(opacity);
}

qreal CFMapMarker::opacity() const
{
    Q_D(const CFMapMarker);
    return d->opacity();
}

void CFMapMarker::setUserData(const QVariant &userData)
{
    Q_D(CFMapMarker);
    d->setUserData(userData);
}

QVariant CFMapMarker::userData() const
{
    Q_D(const CFMapMarker);
    return d->userData();
}

void CFMapMarker::setLayer(CFMapMarkerLayer *layer)
{
    Q_D(CFMapMarker);
    d->setLayer(layer);
}

CFMapMarkerLayer *CFMapMarker::layer() const
{
    Q_D(const CFMapMarker);
    return d->layer();
}

void CFMapMarker::setTappable(bool value)
{
    Q_D(CFMapMarker);
    d->setTappable(value);
}

bool CFMapMarker::tappable() const
{
    Q_D(const CFMapMarker);
    return d->tappable();
}

void CFMapMarker::setZIndex(int zIndex)
{
    Q_D(CFMapMarker);
    d->setZIndex(zIndex);
}

int CFMapMarker::zIndex() const
{
    Q_D(const CFMapMarker);
    return d->zIndex();
}

bool CFMapMarker::active() const
{
    Q_D(const CFMapMarker);
    return d->active();
}

void CFMapMarker::removeFromMap()
{
    Q_D(CFMapMarker);
    d->removeFromMap();
}

void *CFMapMarker::nativeObject() const
{
    Q_D(const CFMapMarker);
    return d->nativeObject();
}
