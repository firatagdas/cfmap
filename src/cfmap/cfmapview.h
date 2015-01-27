#ifndef CFMAPVIEW_H
#define CFMAPVIEW_H

#include <QObject>
#include <QtWebView/private/qwindowcontrolleritem_p.h>
#include "cfmap_global.h"

class CFMapViewPrivate;

class Q_CFMAP_EXPORT CFMapView : public QWindowControllerItem
{
    Q_OBJECT
public:
    CFMapView(QQuickItem *parent = 0);
    ~CFMapView();

protected:
    void componentComplete() Q_DECL_OVERRIDE;

private:
    Q_DECLARE_PRIVATE(CFMapView)
    CFMapViewPrivate *d_ptr;
};

#endif // CFMAPVIEW_H
