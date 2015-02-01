#include "cfmapcoordinate_android_p.h"

CFMapCoordinatePrivate *CFMapCoordinatePrivate::create(CFMapCoordinate *q)
{
    return new CFMapCoordinateAndroidPrivate(q);
}

CFMapCoordinateAndroidPrivate::CFMapCoordinateAndroidPrivate(CFMapCoordinate *q)
    : CFMapCoordinatePrivate(q)
{
}

CFMapCoordinateAndroidPrivate::~CFMapCoordinateAndroidPrivate()
{
}

void CFMapCoordinateAndroidPrivate::setLatitude(qreal latitude)
{
}

qreal CFMapCoordinateAndroidPrivate::latitude() const
{
    return 0.;
}

void CFMapCoordinateAndroidPrivate::setLongitude(qreal longitude)
{
}

qreal CFMapCoordinateAndroidPrivate::longitude() const
{
    return 0.;
}
