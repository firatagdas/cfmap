#ifndef CFMAPMARKER_ANDROID_P_H
#define CFMAPMARKER_ANDROID_P_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include "cfmapmarker_p.h"

class CFMapMarkerAndroidPrivate : public CFMapMarkerPrivate
{
    Q_OBJECT
public:
    CFMapMarkerAndroidPrivate(CFMapMarker *q);
    ~CFMapMarkerAndroidPrivate();

    void setCoordinate(CFMapCoordinate *coordinate);
    CFMapCoordinate *coordinate() const;

    void setTitle(const QString &title);
    QString title() const;

    void setIcon(const QString &icon);
    QString icon() const;

    void setSnippet(const QString &snippet);
    QString snippet() const;

    void setInfoWindowAnchor(const QPointF &point);
    QPointF infoWindowAnchor() const;

    void setGroundAnchor(const QPointF &point);
    QPointF groundAnchor() const;

    void setAnimationType(CFMapMarker::AppearAnimationType animationType);
    CFMapMarker::AppearAnimationType animationType() const;

    void setDraggable(bool value);
    bool draggable() const;

    void setFlat(bool value);
    bool flat() const;

    void setRotation(qreal rotation);
    qreal rotation() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void setUserData(const QVariant &userData);
    QVariant userData() const;

    void setLayer(CFMapMarkerLayer *layer);
    CFMapMarkerLayer *layer() const;

    void setTappable(bool value);
    bool tappable() const;

    void setZIndex(int zIndex);
    int zIndex() const;

    bool active() const;
    void removeFromMap();

    void *nativeObject() const;

};

#endif
