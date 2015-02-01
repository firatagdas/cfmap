#ifndef CFMAPCAMERAPOSITION_P_H
#define CFMAPCAMERAPOSITION_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcameraposition.h"

class CFMapCameraPositionPrivate : public QObject
{
    Q_OBJECT
public:
    CFMapCameraPositionPrivate(CFMapCameraPosition *q)
        : QObject(0)
        , q_ptr(q)
    {}

    virtual ~CFMapCameraPositionPrivate() {}

    static CFMapCameraPositionPrivate *create(CFMapCameraPosition *q);

    virtual void setTarget(CFMapCoordinate *target) = 0;
    virtual CFMapCoordinate *target() const = 0;

    virtual void setZoom(qreal zoom) = 0;
    virtual qreal zoom() const = 0;

    virtual void setBearing(qreal bearing) = 0;
    virtual qreal bearing() const = 0;

    virtual void setViewingAngle(qreal viewingAngle) = 0;
    virtual qreal viewingAngle() const = 0;

    virtual void *nativeObject() const = 0;

    CFMapCameraPosition *q() { return q_ptr; }

private:
    Q_DECLARE_PUBLIC(CFMapCameraPosition)
    CFMapCameraPosition *q_ptr;
};

#endif
