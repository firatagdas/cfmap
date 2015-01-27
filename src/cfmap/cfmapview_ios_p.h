#ifndef CFMAPVIEW_IOS_P_H
#define CFMAPVIEW_IOS_P_H

#include "cfmapview_p.h"

Q_FORWARD_DECLARE_OBJC_CLASS(GMSMapView);

class CFMapViewIosPrivate : public CFMapViewPrivate
{
    Q_OBJECT
public:
    explicit CFMapViewIosPrivate(CFMapView *q);
    virtual ~CFMapViewIosPrivate();

    void *nativeView();

private:
    GMSMapView *m_mapView;
    void *m_delegate;
};

#endif // CFMAPVIEW_IOS_P_H
