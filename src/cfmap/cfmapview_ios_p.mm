#include "cfmapview_ios_p.h"
#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>

@interface CFMapViewDelegate : NSObject<GMSMapViewDelegate>
{
}
@end

@implementation CFMapViewDelegate

@end

CFMapViewPrivate *CFMapViewPrivate::create(CFMapView *q)
{
    return new CFMapViewIosPrivate(q);
}

CFMapViewIosPrivate::CFMapViewIosPrivate(CFMapView *q)
    : CFMapViewPrivate(q)
{
    CGRect frame = CGRectMake(0.0, 0.0, 400, 400);
    m_mapView = [[GMSMapView alloc] initWithFrame:frame];

    CFMapViewDelegate *delegate = [[CFMapViewDelegate alloc] init];
    m_mapView.delegate = delegate;

    m_delegate = (void *) delegate;
}

CFMapViewIosPrivate::~CFMapViewIosPrivate()
{
    [m_mapView release];
}

void *CFMapViewIosPrivate::nativeView()
{
    return (void *) m_mapView;
}

