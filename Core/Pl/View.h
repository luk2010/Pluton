//!
//! @file Pl/View.h
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_VIEW_H__
#define __PL_VIEW_H__

#include "Pl/Platform.h"
#include "Pl/Node.h"

namespace Pl
{
    class PLUTON_EXPORT View : public Node < View >
    {
#       if PLUTON_WINSYS_COCOA
        
        id mHandle;
        
#       endif
        
    public:
        
#       if PLUTON_WINSYS_COCOA
        
        View(id handle);
        
        id handle() const;
        
#       endif
        
        View(const Rect& frame = Rect());
        
        virtual void setFrame(const Rect& rect);
        
        virtual Rect frame() const;
        
        virtual void setBounds(const Rect& rect);
        
        virtual Rect bounds() const;
        
    protected:
        
        virtual bool onWillAddChild(const RefT& child, const RefT& before);
        
        virtual bool onWillRemoveChild(const RefT& child);
    };
}

#endif
