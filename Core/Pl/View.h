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
#include "Pl/DrawerProvider.h"

namespace Pl
{
    class Window;
    
    class PLUTON_EXPORT View : public Node < View >
    {
        friend class Node < View >;
        friend class Window;
        
#       if PLUTON_WINSYS_COCOA
        
        id mHandle;
        
#       endif
        
        std::atomic_bool mLayoutOnNextUpdate;
        
        std::atomic_bool mNeedsLayout;
        
        std::atomic_bool mIsCreated;
        
        Weak < Window > mWindow;
        
        Ref < DrawerProvider > mDrawerProvider;
        
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
        
        virtual void layout();
        
        virtual void layoutIfNeeded();
        
        virtual void update();
        
        virtual void setLayoutOnNextUpdate(bool value);
        
        virtual bool isLayoutOnNextUpdate() const;
        
        virtual Ref < Window > window() const;
        
        virtual Ref < DrawerProvider > drawerProvider() const;
        
        virtual void setDrawerProvider(const Ref < DrawerProvider >& provider);
        
        virtual void draw(Drawer& drawer);
        
        virtual void setNeedsDraw(bool value);
        
        virtual bool needsDraw() const; 
        
    protected:
        
        virtual bool onWillAddChild(const RefT& child, const RefT& before);
        
        virtual bool onWillRemoveChild(const RefT& child);
        
        virtual void onNewParent(const RefT& parent);
        
        virtual void onNewWindow(const Ref < Window >& window);
        
        virtual void onCreate();
    };
}

#endif
