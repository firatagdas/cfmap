#ifndef CFMAPMARKERLAYER_IOS_P_H
#define CFMAPMARKERLAYER_IOS_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarkerlayer_p.h"

Q_FORWARD_DECLARE_OBJC_CLASS(GMSMarkerLayer);

class CFMapMarkerLayerIosPrivate : public CFMapMarkerLayerPrivate
{
    Q_OBJECT
public:
    CFMapMarkerLayerIosPrivate(CFMapMarkerLayer *q);
    ~CFMapMarkerLayerIosPrivate();

    void setCoordinate(CFMapCoordinate *coordinate);
    CFMapCoordinate *coordinate() const;

    void setRotation(qreal rotation);
    qreal rotation() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void *nativeObject() const;

private:
    GMSMarkerLayer *m_markerLayer;
    CFMapCoordinate *m_coordinate;
};

#endif
