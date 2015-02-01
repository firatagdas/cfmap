#ifndef CFMAPMARKERLAYER_DEFAULT_P_H
#define CFMAPMARKERLAYER_DEFAULT_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarkerlayer_p.h"

class CFMapMarkerLayerDefaultPrivate : public CFMapMarkerLayerPrivate
{
    Q_OBJECT
public:
    CFMapMarkerLayerDefaultPrivate(CFMapMarkerLayer *q);
    ~CFMapMarkerLayerDefaultPrivate();

    void setCoordinate(CFMapCoordinate *coordinate);
    CFMapCoordinate *coordinate() const;

    void setRotation(qreal rotation);
    qreal rotation() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void *nativeObject() const;
};

#endif
