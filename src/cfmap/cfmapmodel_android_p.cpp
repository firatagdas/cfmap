#include "cfmapmodel_android_p.h"
#include <QtAndroidExtras>
#include <QJsonDocument>
#include <CFMvc/cfandroidutil.h>

CFMapModelPrivate *CFMapModelPrivate::create(CFMapModel *q)
{
    return new CFMapModelAndroidPrivate(q);
}

CFMapModelAndroidPrivate::CFMapModelAndroidPrivate(CFMapModel *q)
    : CFMapModelPrivate(q)
    , m_id(reinterpret_cast<quintptr>(this))
{
}

CFMapModelAndroidPrivate::~CFMapModelAndroidPrivate()
{
}

void CFMapModelAndroidPrivate::init()
{

}

void CFMapModelAndroidPrivate::init(const QString &apiKey)
{
    Q_UNUSED(apiKey)
}

