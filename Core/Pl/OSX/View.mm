//!
//! @file Pl/View.mm
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/View.h"
#include "Pl/OSX/PLView.h"
#include "Pl/OSX/OSXDrawerProvider.h"

namespace Pl
{
    View::View(id handle): mHandle(handle)
    {
        mLayoutOnNextUpdate = true;
        mNeedsLayout = false;
        mIsCreated = false;
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
        mLayoutOnNextUpdate = true;
        mNeedsLayout = false;
        mIsCreated = false;
    }
    
    void View::setFrame(const Rect& rect)
    {
        [(NSView*)mHandle setFrame:NSMakeRect(rect.origin.x,
                                              rect.origin.y,
                                              rect.size.width,
                                              rect.size.height)];
        
        layoutIfNeeded();
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
        
        layoutIfNeeded();
    }
    
    Rect View::bounds() const
    {
        NSRect fr = [(NSView*)mHandle bounds];
        
        return Rect({ fr.origin.x, fr.origin.y}, { fr.size.width, fr.size.height });
    }
    
    void View::layout()
    {
        
    }
    
    void View::layoutIfNeeded()
    {
        if (mLayoutOnNextUpdate)
            mNeedsLayout = true;
        else
            layout();
    }
    
    void View::update()
    {
        if (mNeedsLayout.exchange(false))
            layout();
        
        for (size_t i = 0; i < childrenCount(); ++i)
            child(i)->update();
    }
    
    void View::setLayoutOnNextUpdate(bool value)
    {
        mLayoutOnNextUpdate = value;
    }
    
    bool View::isLayoutOnNextUpdate() const
    {
        return mLayoutOnNextUpdate;
    }
    
    Ref < Window > View::window() const
    {
        return mWindow.lock();
    }
    
    Ref < DrawerProvider > View::drawerProvider() const
    {
        return mDrawerProvider;
    }
    
    void View::setDrawerProvider(const Ref < DrawerProvider >& provider)
    {
        mDrawerProvider = provider;
    }
    
    void View::draw(Drawer& drawer)
    {
        /* Please implement this as you want... */
    }
    
    void View::setNeedsDraw(bool value)
    {
        [(NSView*)mHandle setNeedsDisplay:(BOOL)value];
    }
    
    bool View::needsDraw() const
    {
        return [(NSView*)mHandle needsDisplay];
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
    
    void View::onNewParent(const RefT& parent)
    {
        Node < View >::onNewParent(parent);
        
        if (!mIsCreated.exchange(false))
            onCreate();
    }
    
    void View::onNewWindow(const Ref < Window >& window)
    {
        mWindow = window;
        
        if (!mIsCreated.exchange(false))
            onCreate();
        
        for (size_t i = 0; i < childrenCount(); ++i)
            child(i)->onNewWindow(window);
    }
    
    void View::onCreate()
    {
        mDrawerProvider = Make < OSXDrawerProvider >();
    }
}
