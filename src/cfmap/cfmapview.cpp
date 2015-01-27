#include "cfmapview.h"
#include "cfmapview_p.h"

CFMapView::CFMapView(QQuickItem *parent)
    : QWindowControllerItem(parent)
    , d_ptr(CFMapViewPrivate::create(this))
{
    WId id(WId(d_ptr->nativeView()));
    if (id != 0)
        setNativeWindow(id);
    else
        qWarning() << "No native view. Missing platform support?";
}

CFMapView::~CFMapView()
{
    delete d_ptr;
}

void CFMapView::componentComplete()
{
    QWindowControllerItem::componentComplete();
}

