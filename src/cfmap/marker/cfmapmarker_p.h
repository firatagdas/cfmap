#ifndef CFMAPMARKER_P_H
#define CFMAPMARKER_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarker.h"

class CFMapMarkerPrivate : public QObject
{
    Q_OBJECT
public:
    CFMapMarkerPrivate(CFMapMarker *q)
        : QObject(0)
        , q_ptr(q)
    {}

    virtual ~CFMapMarkerPrivate() {}

    static CFMapMarkerPrivate *create(CFMapMarker *q);

    virtual void setCoordinate(CFMapCoordinate *coordinate) = 0;
    virtual CFMapCoordinate *coordinate() const = 0;

    virtual void setText(const QString &text) = 0;
    virtual QString text() const = 0;

    virtual void setTitle(const QString &title) = 0;
    virtual QString title() const = 0;

    virtual void setIcon(const QString &icon) = 0;
    virtual QString icon() const = 0;

    virtual void setSnippet(const QString &snippet) = 0;
    virtual QString snippet() const = 0;

    virtual void setInfoWindowAnchor(const QPointF &point) = 0;
    virtual QPointF infoWindowAnchor() const = 0;

    virtual void setGroundAnchor(const QPointF &point) = 0;
    virtual QPointF groundAnchor() const = 0;

    virtual void setAnimationType(CFMapMarker::AppearAnimationType animationType) = 0;
    virtual CFMapMarker::AppearAnimationType animationType() const = 0;

    virtual void setDraggable(bool value) = 0;
    virtual bool draggable() const = 0;

    virtual void setFlat(bool value) = 0;
    virtual bool flat() const = 0;

    virtual void setRotation(qreal rotation) = 0;
    virtual qreal rotation() const = 0;

    virtual void setOpacity(qreal opacity) = 0;
    virtual qreal opacity() const = 0;

    virtual void setUserData(const QVariant &userData) = 0;
    virtual QVariant userData() const = 0;

    virtual void setLayer(CFMapMarkerLayer *layer) = 0;
    virtual CFMapMarkerLayer *layer() const = 0;

    virtual void setTappable(bool value) = 0;
    virtual bool tappable() const = 0;

    virtual void setZIndex(int zIndex) = 0;
    virtual int zIndex() const = 0;

    virtual bool active() const = 0;
    virtual void removeFromMap() = 0;

    virtual void *nativeObject() const = 0;

    CFMapMarker *q() { return q_ptr; }

private:
    Q_DECLARE_PUBLIC(CFMapMarker)
    CFMapMarker *q_ptr;
};

#endif
