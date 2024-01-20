//!
//! @file PLView.mm
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/PLView.h"

@implementation PLView

- (instancetype)initWithPl:(Pl::View *)hdl frameRect:(NSRect)rect
{
    self = [super initWithFrame:rect];
    
    if (self)
    {
        [self setPl:hdl];
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    Pl::View* view = [self Pl];
    
    if (!view)
        return;
    
    Pl::Ref < Pl::DrawerProvider > provider = view->drawerProvider();
    
    if (!provider)
        return;
    
    Pl::Ref < Pl::Drawer > drawer = provider->createDrawer();
    
    if (!drawer)
        return;
    
    view->draw(*drawer);
}

@end
