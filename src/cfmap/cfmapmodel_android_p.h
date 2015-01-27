#ifndef CFMAPMODEL_ANDROID_P_H
#define CFMAPMODEL_ANDROID_P_H

#include "cfmapmodel_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtCore/private/qjni_p.h>

class CFMapModelAndroidPrivate : public CFMapModelPrivate
{
    Q_OBJECT
public:
    explicit CFMapModelAndroidPrivate(CFMapModel *q);
    ~CFMapModelAndroidPrivate();

    void init();
    void init(const QString &apiKey);

private:
    quintptr m_id;
    QJNIObjectPrivate m_mapController;
};

#endif // CFMAPMODEL_ANDROID_P_H
