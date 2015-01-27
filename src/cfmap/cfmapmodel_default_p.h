#ifndef CFMAPMODEL_DEFAULT_P_H
#define CFMAPMODEL_DEFAULT_P_H

#include "cfmapmodel_p.h"

class CFMapModelDefaultPrivate : public CFMapModelPrivate
{
    Q_OBJECT
public:
    explicit CFMapModelDefaultPrivate(CFMapModel *q);
    ~CFMapModelDefaultPrivate();

    void init();
    void init(const QString &apiKey);
};

#endif // CFMAPMODEL_DEFAULT_P_H
