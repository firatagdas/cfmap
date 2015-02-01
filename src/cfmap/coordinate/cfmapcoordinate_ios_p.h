#ifndef CFMAPCOORDINATE_IOS_P_H
#define CFMAPCOORDINATE_IOS_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcoordinate_p.h"

class CFMapCoordinateIosPrivate : public CFMapCoordinatePrivate
{
    Q_OBJECT
public:
    CFMapCoordinateIosPrivate(CFMapCoordinate *q);
    ~CFMapCoordinateIosPrivate();

    void setLatitude(qreal latitude);
    qreal latitude() const;

    void setLongitude(qreal longitude);
    qreal longitude() const;

private:
    qreal m_latitude;
    qreal m_longitude;
};

#endif
