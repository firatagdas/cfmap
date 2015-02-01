#include "cfmapcoordinate_ios_p.h"

CFMapCoordinatePrivate *CFMapCoordinatePrivate::create(CFMapCoordinate *q)
{
    return new CFMapCoordinateIosPrivate(q);
}

CFMapCoordinateIosPrivate::CFMapCoordinateIosPrivate(CFMapCoordinate *q)
    : CFMapCoordinatePrivate(q)
    , m_latitude(0.)
    , m_longitude(0.)
{
}

CFMapCoordinateIosPrivate::~CFMapCoordinateIosPrivate()
{
}

void CFMapCoordinateIosPrivate::setLatitude(qreal latitude)
{
    if (m_latitude != latitude) {
        m_latitude = latitude;
        Q_EMIT q()->latitudeChanged();
    }
}

qreal CFMapCoordinateIosPrivate::latitude() const
{
    return m_latitude;
}

void CFMapCoordinateIosPrivate::setLongitude(qreal longitude)
{
    if (m_longitude != longitude) {
        m_longitude = longitude;
        Q_EMIT q()->longitudeChanged();
    }
}

qreal CFMapCoordinateIosPrivate::longitude() const
{
    return m_longitude;
}
