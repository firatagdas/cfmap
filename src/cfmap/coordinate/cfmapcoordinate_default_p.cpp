#include "cfmapcoordinate_default_p.h"

CFMapCoordinatePrivate *CFMapCoordinatePrivate::create(CFMapCoordinate *q)
{
    return new CFMapCoordinateDefaultPrivate(q);
}

CFMapCoordinateDefaultPrivate::CFMapCoordinateDefaultPrivate(CFMapCoordinate *q)
    : CFMapCoordinatePrivate(q)
{
}

CFMapCoordinateDefaultPrivate::~CFMapCoordinateDefaultPrivate()
{
}

void CFMapCoordinateDefaultPrivate::setLatitude(qreal latitude)
{
}

qreal CFMapCoordinateDefaultPrivate::latitude() const
{
    return 0.;
}

void CFMapCoordinateDefaultPrivate::setLongitude(qreal longitude)
{
}

qreal CFMapCoordinateDefaultPrivate::longitude() const
{
    return 0.;
}
