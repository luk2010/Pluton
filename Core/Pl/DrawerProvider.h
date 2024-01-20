//!
//! @file Pl/DrawerProvider.h
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_DRAWERPROVIDER_H__
#define __PL_DRAWERPROVIDER_H__

#include "Pl/Drawer.h"

namespace Pl
{
    class DrawerProvider
    {
    public:
        
        virtual ~DrawerProvider() = default;
        
        virtual Ref < Drawer > createDrawer() = 0;
    };
}

#endif
