#include "cfmapmodel.h"
#include "cfmapmodel_p.h"

Q_LOGGING_CATEGORY(CFMapModelTag, "com.cf.map.CFMapModel")

CFMVC_MODEL_BEGIN(CFMapModel)

CFMapModel::CFMapModel(CFMvc *mvc, const QVariantMap &config)
    : CFModel(mvc, config)
    , d_ptr(CFMapModelPrivate::create(this))
{
}

CFMapModel::~CFMapModel()
{
    delete d_ptr;
}

void CFMapModel::init()
{
    Q_D(CFMapModel);
    d->init();
}

void CFMapModel::init(const QString &apiKey)
{
    Q_D(CFMapModel);
    d->init(apiKey);
}

void CFMapModel::setView(CFMapView *view)
{
    Q_D(CFMapModel);
    if (d->m_view != view) {
        d->m_view = view;
        Q_EMIT viewChanged();
    }
}

CFMapView *CFMapModel::view() const
{
    Q_D(const CFMapModel);
    return d->m_view;
}

CFMVC_MODEL_END(CFMapModel)

