//!
//! @file Pl/View.mm
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/View.h"
#include "Pl/OSX/PLView.h"

namespace Pl
{
    View::View(id handle): mHandle(handle)
    {
        
    }
    
    id View::handle() const
    {
        return mHandle;
    }
    
    View::View(const Rect& rect): mHandle([[PLView alloc] initWithPl:this
                                                           frameRect:NSMakeRect(rect.origin.x,
                                                                                rect.origin.y,
                                                                                rect.size.width,
                                                                                rect.size.height)])
    {
        
    }
    
    void View::setFrame(const Rect& rect)
    {
        [(NSView*)mHandle setFrame:NSMakeRect(rect.origin.x,
                                              rect.origin.y,
                                              rect.size.width,
                                              rect.size.height)];
    }
    
    Rect View::frame() const
    {
        NSRect fr = [(NSView*)mHandle frame];
        
        return Rect({ fr.origin.x, fr.origin.y}, { fr.size.width, fr.size.height });
    }
    
    void View::setBounds(const Rect& rect)
    {
        [(NSView*)mHandle setBounds:NSMakeRect(rect.origin.x,
                                               rect.origin.y,
                                               rect.size.width,
                                               rect.size.height)];
    }
    
    Rect View::bounds() const
    {
        NSRect fr = [(NSView*)mHandle bounds];
        
        return Rect({ fr.origin.x, fr.origin.y}, { fr.size.width, fr.size.height });
    }
    
    bool View::onWillAddChild(const RefT& child, const RefT& before)
    {
        NSView* cHdl = child->handle();
        NSView* bHdl = before ? before->handle() : nil;
        
        [(NSView*)mHandle addSubview:cHdl
                          positioned:NSWindowBelow
                          relativeTo:bHdl];
        
        return true;
    }
    
    bool View::onWillRemoveChild(const RefT& child)
    {
        [(NSView*)child->handle() removeFromSuperview];
        return true;
    }
}
