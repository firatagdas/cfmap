#ifndef CFMAPCOORDINATE_P_H
#define CFMAPCOORDINATE_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcoordinate.h"

class CFMapCoordinatePrivate : public QObject
{
    Q_OBJECT
public:
    CFMapCoordinatePrivate(CFMapCoordinate *q)
        : QObject(0)
        , q_ptr(q)
    {}

    virtual ~CFMapCoordinatePrivate();

    static CFMapCoordinatePrivate *create(CFMapCoordinate *q);

    virtual void setLatitude(qreal latitude) = 0;
    virtual qreal latitude() const = 0;

    virtual void setLongitude(qreal longitude) = 0;
    virtual qreal longitude() const = 0;

    CFMapCoordinate *q() { return q_ptr; }

private:
    Q_DECLARE_PUBLIC(CFMapCoordinate)
    CFMapCoordinate *q_ptr;
};

#endif
