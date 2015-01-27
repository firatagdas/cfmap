#ifndef CFMAPMODEL_H
#define CFMAPMODEL_H

#include <CFMvc/cfmodel.h>
#include <QLoggingCategory>
#include "cfmap_global.h"

Q_DECLARE_LOGGING_CATEGORY(CFMapModelTag)

class CFMapModelPrivate;
class CFMapView;

class Q_CFMAP_EXPORT CFMapModel : public CFModel
{
    Q_OBJECT
    CFMVC_MODEL_OBJECT(CFMapModel)

public:
    explicit CFMapModel(CFMvc *mvc, const QVariantMap &config = QVariantMap());
    ~CFMapModel();

    Q_INVOKABLE void init();
    Q_INVOKABLE void init(const QString &apiKey);

    void setView(CFMapView *view);
    CFMapView *view() const;

Q_SIGNALS:
    void viewChanged();

private:
    Q_DECLARE_PRIVATE(CFMapModel)
    CFMapModelPrivate *d_ptr;
};

#endif // CFMAPMODEL_H
