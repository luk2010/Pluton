//!
//! @file Pl/Window.h
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_WINDOW_H__
#define __PL_WINDOW_H__

#include "Pl/Platform.h"
#include "Pl/View.h"

namespace Pl
{
    class PLUTON_EXPORT Window
    {
#       if PLUTON_WINSYS_COCOA
        
        id mHandle;
        
        id mDelegate;
        
#       endif
        
        Ref < View > mContentView;
        
    public:
        
        struct PLUTON_EXPORT Style
        {
            bool closable :1;
            bool resizable :1;
            bool titled :1;
            
            inline Style()
            {
                closable = true;
                resizable = true;
                titled = true;
            }
        };
        
    public:
        
        Window(const Rect& rect, const Style& style, const std::string& title);
        
#       if PLUTON_WINSYS_COCOA
        
        Window(id handle);
        
        virtual id handle() const;
        
#       endif
        
        virtual ~Window();
        
        virtual void setFrame(const Rect& rect);
        
        virtual Rect frame() const;
        
        virtual Rect frameOfContent() const;
        
        virtual void setStyle(const Style& style);
        
        virtual Style style() const;
        
        virtual void setTitle(const std::string& title);
        
        virtual std::string title() const;
        
        virtual void show();
        
        virtual void center();
        
        virtual void close();
        
        virtual void setContentView(const Ref < View >& view);
        
        virtual Ref < View > contentView() const;
        
    public:
        
        virtual void onMove(const Point& newOrigin);
        
        virtual void onSize(const Size& newSize);
        
        virtual void onClose();
    };
}

#endif
