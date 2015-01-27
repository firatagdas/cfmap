#ifndef CFMAPMODELPRIVATE_H
#define CFMAPMODELPRIVATE_H

#include <QObject>
#include <QtWebView/private/qwindowcontrolleritem_p.h>
#include "cfmapmodel.h"

class CFMapModelPrivate : public QObject
{
    Q_OBJECT
public:
    explicit CFMapModelPrivate(CFMapModel *q)
        : QObject(0)
        , q_ptr(q)
        , m_view(0)
    {}
    virtual ~CFMapModelPrivate() {}

    static CFMapModelPrivate *create(CFMapModel *q);

    CFMapModel *q() { return q_ptr; }

    virtual void init() = 0;
    virtual void init(const QString &apiKey) = 0;

private:
    Q_DECLARE_PUBLIC(CFMapModel)
    CFMapModel *q_ptr;

    CFMapView *m_view;
};



#endif // CFMAPMODELPRIVATE_H
