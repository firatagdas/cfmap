#include "cfmapcoordinate.h"
#include "cfmapcoordinate_p.h"

CFMapCoordinate::CFMapCoordinate(QObject *parent)
    : QObject(parent)
    , d_ptr(CFMapCoordinatePrivate::create(this))
{
}

CFMapCoordinate::~CFMapCoordinate()
{
    delete d_ptr;
}

void CFMapCoordinate::setLatitude(qreal latitude)
{
    Q_D(CFMapCoordinate);
    d->setLatitude(latitude);
}

qreal CFMapCoordinate::latitude() const
{
    Q_D(const CFMapCoordinate);
    return d->latitude();
}

void CFMapCoordinate::setLongitude(qreal longitude)
{
    Q_D(CFMapCoordinate);
    d->setLongitude(longitude);
}

qreal CFMapCoordinate::longitude() const
{
    Q_D(const CFMapCoordinate);
    return d->longitude();
}

bool CFMapCoordinate::operator==(CFMapCoordinate *other)
{
    Q_D(const CFMapCoordinate);
    return (other->latitude() == d->latitude() && other->longitude() == d->longitude());
}
