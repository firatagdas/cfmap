#ifndef CFMAPMARKERLAYER_ANDROID_P_H
#define CFMAPMARKERLAYER_ANDROID_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarkerlayer_p.h"

class CFMapMarkerLayerAndroidPrivate : public CFMapMarkerLayerPrivate
{
    Q_OBJECT
public:
    CFMapMarkerLayerAndroidPrivate(CFMapMarkerLayer *q);
    ~CFMapMarkerLayerAndroidPrivate();

    void setCoordinate(CFMapCoordinate *coordinate);
    CFMapCoordinate *coordinate() const;

    void setRotation(qreal rotation);
    qreal rotation() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void *nativeObject() const;

};

#endif
