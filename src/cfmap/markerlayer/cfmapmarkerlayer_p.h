#ifndef CFMAPMARKERLAYER_P_H
#define CFMAPMARKERLAYER_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarkerlayer.h"

class CFMapMarkerLayerPrivate : public QObject
{
    Q_OBJECT
public:
    CFMapMarkerLayerPrivate(CFMapMarkerLayer *q)
        : QObject(0)
        , q_ptr(q)
    {}

    virtual ~CFMapMarkerLayerPrivate();

    static CFMapMarkerLayerPrivate *create(CFMapMarkerLayer *q);

    virtual void setCoordinate(CFMapCoordinate *coordinate) = 0;
    virtual CFMapCoordinate *coordinate() const = 0;

    virtual void setRotation(qreal rotation) = 0;
    virtual qreal rotation() const = 0;

    virtual void setOpacity(qreal opacity) = 0;
    virtual qreal opacity() const = 0;

    virtual void *nativeObject() const = 0;

    CFMapMarkerLayer *q() { return q_ptr; }

private:
    Q_DECLARE_PUBLIC(CFMapMarkerLayer)
    CFMapMarkerLayer *q_ptr;
};

#endif
