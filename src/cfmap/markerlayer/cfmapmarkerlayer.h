#ifndef CFMAPMARKERLAYER_H
#define CFMAPMARKERLAYER_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"

class CFMapMarkerLayerPrivate;
class CFMapCoordinate;

class Q_CFMAP_EXPORT CFMapMarkerLayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CFMapCoordinate * coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)

public:
    CFMapMarkerLayer(QObject *parent = 0);
    ~CFMapMarkerLayer();

    void setCoordinate(CFMapCoordinate *coordinate);
    CFMapCoordinate *coordinate() const;

    void setRotation(qreal rotation);
    qreal rotation() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void *nativeObject() const;

Q_SIGNALS:
    void coordinateChanged();
    void rotationChanged();
    void opacityChanged();

private:
    Q_DECLARE_PRIVATE(CFMapMarkerLayer)
    CFMapMarkerLayerPrivate *d_ptr;
};

QML_DECLARE_TYPE(CFMapMarkerLayer)

#endif
