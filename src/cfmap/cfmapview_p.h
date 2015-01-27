#ifndef CFMAPVIEW_P
#define CFMAPVIEW_P

#include <QObject>

class CFMapView;

class CFMapViewPrivate : public QObject
{
    Q_OBJECT
public:
    explicit CFMapViewPrivate(CFMapView *q)
        : QObject(0)
        , q_ptr(q)
    {}
    virtual ~CFMapViewPrivate() {}
    static CFMapViewPrivate *create(CFMapView *q);
    CFMapView *q() { return q_ptr; }

    virtual void *nativeView() = 0;

protected:
    Q_DECLARE_PUBLIC(CFMapView)
    CFMapView *q_ptr;
};

#endif // CFMAPVIEW_P

