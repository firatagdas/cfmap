#ifndef CFMAPMODEL_IOS_P_H
#define CFMAPMODEL_IOS_P_H

#include "cfmapmodel_p.h"

class CFMapModelIosPrivate : public CFMapModelPrivate
{
    Q_OBJECT
public:
    explicit CFMapModelIosPrivate(CFMapModel *q);
    ~CFMapModelIosPrivate();

    void init();
    void init(const QString &apiKey);
};

#endif // CFMAPMODEL_IOS_P_H
