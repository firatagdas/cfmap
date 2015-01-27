#include "cfmapmodel_default_p.h"

CFMapModelPrivate *CFMapModelPrivate::create(CFMapModel *q)
{
    return new CFMapModelDefaultPrivate(q);
}

CFMapModelDefaultPrivate::CFMapModelDefaultPrivate(CFMapModel *q)
    : CFMapModelPrivate(q)
{
}

CFMapModelDefaultPrivate::~CFMapModelDefaultPrivate()
{
}

void CFMapModelDefaultPrivate::init()
{

}

void CFMapModelDefaultPrivate::init(const QString &apiKey)
{
    Q_UNUSED(apiKey)
}
