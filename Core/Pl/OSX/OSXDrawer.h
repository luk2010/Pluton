//!
//! @file Pl/OSX/OSXDrawer.h
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_OSXDRAWER_H__
#define __PL_OSXDRAWER_H__

#include "Pl/Drawer.h"

namespace Pl
{
    class OSXDrawer : public Drawer
    {
        NSGraphicsContext* mHandle;
        
    public:
        
        OSXDrawer(NSGraphicsContext* hdl);
        
        virtual void setFillColor(const RGBAColor& color);
        
        virtual void setStrokeColor(const RGBAColor& color);
        
        virtual void fill(const Rect& rect, double cornerRadius);
        
        virtual void stroke(const Rect& rect, double lineWidth, double cornerRadius);
        
        virtual void fill(const Path& path);
        
        virtual void stroke(const Path& path, double lineWidth);
        
    protected:
        
        virtual void setPath(const Path& path);
    };
}

#endif
