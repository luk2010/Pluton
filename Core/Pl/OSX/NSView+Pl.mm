//!
//! @file NSView+Pl.mm
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/NSView+Pl.h"

static const char kNSViewPlKey = 0;

@implementation NSView (Pl)

- (Pl::View*) Pl
{
    return (Pl::View*) objc_getAssociatedObject(self, &kNSViewPlKey);
}

- (void) setPl:(Pl::View *)hdl
{
    objc_setAssociatedObject(self,
                             &kNSViewPlKey,
                             (__bridge id)hdl,
                             OBJC_ASSOCIATION_ASSIGN);
}

@end
