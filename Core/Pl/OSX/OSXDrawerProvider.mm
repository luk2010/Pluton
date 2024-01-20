//!
//! @file Pl/OSX/OSXDrawerProvider.mm
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/OSXDrawerProvider.h"
#include "Pl/OSX/OSXDrawer.h"

namespace Pl
{
    Ref < Drawer > OSXDrawerProvider::createDrawer()
    {
        NSGraphicsContext* hdl = [NSGraphicsContext currentContext];
        
        if (!hdl)
            return nullptr;
        
        return Make < OSXDrawer >(hdl);
    }
}
