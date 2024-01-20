//!
//! @file Pl/OSX/OSXDrawerProvider.h
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_OSXDRAWERPROVIDER_H__
#define __PL_OSXDRAWERPROVIDER_H__

#include "Pl/DrawerProvider.h"

namespace Pl
{
    class OSXDrawerProvider : public DrawerProvider
    {
    public:
        
        virtual Ref < Drawer > createDrawer();
    };
}

#endif
