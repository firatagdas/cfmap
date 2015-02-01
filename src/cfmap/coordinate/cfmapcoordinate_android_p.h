#ifndef CFMAPCOORDINATE_ANDROID_P_H
#define CFMAPCOORDINATE_ANDROID_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcoordinate_p.h"

class CFMapCoordinateAndroidPrivate : public CFMapCoordinatePrivate
{
    Q_OBJECT
public:
    CFMapCoordinateAndroidPrivate(CFMapCoordinate *q);
    ~CFMapCoordinateAndroidPrivate();

    void setLatitude(qreal latitude);
    qreal latitude() const;

    void setLongitude(qreal longitude);
    qreal longitude() const;

};

#endif
