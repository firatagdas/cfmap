#ifndef CFMAPVIEW_ANDROID_P_H
#define CFMAPVIEW_ANDROID_P_H

#include "cfmapview_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtCore/private/qjni_p.h>

class CFMapViewAndroidPrivate : public CFMapViewPrivate
{
    Q_OBJECT
public:
    explicit CFMapViewAndroidPrivate(CFMapView *q);
    virtual ~CFMapViewAndroidPrivate();

    void *nativeView();

private:
    quintptr m_id;
    QJNIObjectPrivate m_mapController;
    QJNIObjectPrivate m_mapView;
    void *m_delegate;
};

#endif // CFMAPVIEW_ANDROID_P_H
