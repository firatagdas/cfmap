#include "cfmapmodel_ios_p.h"

#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>

CFMapModelPrivate *CFMapModelPrivate::create(CFMapModel *q)
{
    return new CFMapModelIosPrivate(q);
}

CFMapModelIosPrivate::CFMapModelIosPrivate(CFMapModel *q)
    : CFMapModelPrivate(q)
{
}

CFMapModelIosPrivate::~CFMapModelIosPrivate()
{
}

void CFMapModelIosPrivate::init()
{
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *apiKey = [infoDict objectForKey:@"CFMapApiKey"];

    init(QString::fromNSString(apiKey));
}

void CFMapModelIosPrivate::init(const QString &apiKey)
{
    [GMSServices provideAPIKey:[[NSString alloc] initWithFormat:@"%s", apiKey.toUtf8().data()]];
}

