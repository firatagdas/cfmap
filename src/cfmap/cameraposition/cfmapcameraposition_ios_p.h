#ifndef CFMAPCAMERAPOSITION_IOS_P_H
#define CFMAPCAMERAPOSITION_IOS_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapcameraposition_p.h"

Q_FORWARD_DECLARE_OBJC_CLASS(GMSCameraPosition);

class CFMapCameraPositionIosPrivate : public CFMapCameraPositionPrivate
{
    Q_OBJECT
public:
    CFMapCameraPositionIosPrivate(CFMapCameraPosition *q);
    ~CFMapCameraPositionIosPrivate();

    void setTarget(CFMapCoordinate *target);
    CFMapCoordinate *target() const;

    void setZoom(qreal zoom);
    qreal zoom() const;

    void setBearing(qreal bearing);
    qreal bearing() const;

    void setViewingAngle(qreal viewingAngle);
    qreal viewingAngle() const;

    void *nativeObject() const;

    void restoreNativeObject();
private:
    CFMapCoordinate *m_target;
    qreal m_zoom;
    qreal m_bearing;
    qreal m_viewingAngle;
    GMSCameraPosition *m_cameraPosition;
};

#endif
