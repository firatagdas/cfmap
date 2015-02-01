#ifndef CFMAPMARKER_H
#define CFMAPMARKER_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"
#include <QPointF>

class CFMapCoordinate;
class CFMapMarkerLayer;
class CFMapMarkerPrivate;

class Q_CFMAP_EXPORT CFMapMarker : public QObject
{
    Q_OBJECT
    Q_ENUMS(AppearAnimationType)
    Q_PROPERTY(CFMapCoordinate * coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QString snippet READ snippet WRITE setSnippet NOTIFY snippetChanged)
    Q_PROPERTY(QPointF infoWindowAnchor READ infoWindowAnchor WRITE setInfoWindowAnchor NOTIFY infoWindowAnchorChanged)
    Q_PROPERTY(QPointF groundAnchor READ groundAnchor WRITE setGroundAnchor NOTIFY groundAnchorChanged)
    Q_PROPERTY(AppearAnimationType animationType READ animationType WRITE setAnimationType NOTIFY animationTypeChanged)
    Q_PROPERTY(bool draggable READ draggable WRITE setDraggable NOTIFY draggableChanged)
    Q_PROPERTY(bool flat READ flat WRITE setFlat NOTIFY flatChanged)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)
    Q_PROPERTY(QVariant userData READ userData WRITE setUserData NOTIFY userDataChanged)
    Q_PROPERTY(CFMapMarkerLayer * layer READ layer WRITE setLayer NOTIFY layerChanged)
    Q_PROPERTY(bool tappable READ tappable WRITE setTappable NOTIFY tappableChanged)
    Q_PROPERTY(int zIndex READ zIndex WRITE setZIndex NOTIFY zIndexChanged)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)

public:
    enum AppearAnimationType {
        AppearAnimationNone,
        AppearAnimationPop
    };

    CFMapMarker(QObject *parent = 0);
    ~CFMapMarker();

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

    void setAnimationType(AppearAnimationType animationType);
    AppearAnimationType animationType() const;

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
    Q_INVOKABLE void removeFromMap();

    void *nativeObject() const;

Q_SIGNALS:
    void coordinateChanged();
    void titleChanged();
    void iconChanged();
    void snippetChanged();
    void infoWindowAnchorChanged();
    void groundAnchorChanged();
    void animationTypeChanged();
    void draggableChanged();
    void flatChanged();
    void rotationChanged();
    void opacityChanged();
    void userDataChanged();
    void layerChanged();
    void tappableChanged();
    void zIndexChanged();
    void activeChanged();

private:
    Q_DECLARE_PRIVATE(CFMapMarker)
    CFMapMarkerPrivate *d_ptr;
};


#endif
