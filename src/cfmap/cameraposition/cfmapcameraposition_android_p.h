#ifndef CFMAPCAMERAPOSITION_ANDROID_P_H
#define CFMAPCAMERAPOSITION_ANDROID_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcameraposition_p.h"

class CFMapCameraPositionAndroidPrivate : public CFMapCameraPositionPrivate
{
    Q_OBJECT
public:
    CFMapCameraPositionAndroidPrivate(CFMapCoordinate *q);
    ~CFMapCameraPositionAndroidPrivate();

    void setTarget(CFMapCoordinate *target);
    CFMapCoordinate *target() const;

    void setZoom(qreal zoom);
    qreal zoom() const;

    void setBearing(qreal bearing);
    qreal bearing() const;

    void setViewingAngle(qreal viewingAngle);
    qreal viewingAngle() const;

    void *nativeObject() const;

};

#endif
