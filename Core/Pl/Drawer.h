//!
//! @file Pl/Drawer.h
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_DRAWER_H__
#define __PL_DRAWER_H__

#include "Pl/Platform.h"
#include "Pl/Path.h"

namespace Pl
{
    class Drawer
    {
    public:
        
        virtual ~Drawer() = default;
        
        virtual void setFillColor(const RGBAColor& color) = 0;
        
        virtual void setStrokeColor(const RGBAColor& color) = 0;
        
        virtual void fill(const Rect& rect, double cornerRadius) = 0;
        
        virtual void stroke(const Rect& rect, double lineWidth, double cornerRadius) = 0;
        
        virtual void fill(const Path& path) = 0;
        
        virtual void stroke(const Path& path, double lineWidth) = 0;
    };
}

#endif
