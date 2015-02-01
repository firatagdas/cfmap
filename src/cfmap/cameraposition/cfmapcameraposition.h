#ifndef CFMAPCAMERAPOSITION_H
#define CFMAPCAMERAPOSITION_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"

class CFMapCameraPositionPrivate;
class CFMapCoordinate;

class Q_CFMAP_EXPORT CFMapCameraPosition : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CFMapCoordinate * target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(qreal zoom READ zoom WRITE setZoom NOTIFY zoomChanged)
    Q_PROPERTY(qreal bearing READ bearing WRITE setBearing NOTIFY bearingChanged)
    Q_PROPERTY(qreal viewingAngle READ viewingAngle WRITE setViewingAngle NOTIFY viewingAngleChanged)

public:
    CFMapCameraPosition(QObject *parent = 0);
    ~CFMapCameraPosition();

    void setTarget(CFMapCoordinate *target);
    CFMapCoordinate *target() const;

    void setZoom(qreal zoom);
    qreal zoom() const;

    void setBearing(qreal bearing);
    qreal bearing() const;

    void setViewingAngle(qreal viewingAngle);
    qreal viewingAngle() const;

    void *nativeObject() const;

Q_SIGNALS:
    void targetChanged();
    void zoomChanged();
    void bearingChanged();
    void viewingAngleChanged();

private:
    Q_DECLARE_PRIVATE(CFMapCameraPosition)
    CFMapCameraPositionPrivate *d_ptr;
};

QML_DECLARE_TYPE(CFMapCameraPosition)

#endif
