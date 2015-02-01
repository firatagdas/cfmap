#ifndef CFMAPCOORDINATE_DEFAULT_P_H
#define CFMAPCOORDINATE_DEFAULT_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcoordinate_p.h"

class CFMapCoordinateDefaultPrivate : public CFMapCoordinatePrivate
{
    Q_OBJECT
public:
    CFMapCoordinateDefaultPrivate(CFMapCoordinate *q);
    ~CFMapCoordinateDefaultPrivate();

    void setLatitude(qreal latitude);
    qreal latitude() const;

    void setLongitude(qreal longitude);
    qreal longitude() const;
};

#endif
