#ifndef CFMAPCOORDINATE_H
#define CFMAPCOORDINATE_H

#include <QObject>
#include <qqml.h>
#include "cfmap_global.h"

class CFMapCoordinatePrivate;

class Q_CFMAP_EXPORT CFMapCoordinate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)

public:
    CFMapCoordinate(QObject *parent = 0);
    ~CFMapCoordinate();

    void setLatitude(qreal latitude);
    qreal latitude() const;

    void setLongitude(qreal longitude);
    qreal longitude() const;

    bool operator==(CFMapCoordinate *other);

Q_SIGNALS:
    void latitudeChanged();
    void longitudeChanged();

private:
    Q_DECLARE_PRIVATE(CFMapCoordinate)
    CFMapCoordinatePrivate *d_ptr;
};

#endif
