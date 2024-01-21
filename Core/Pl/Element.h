//!
//! @file Pl/Element.h
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_ELEMENT_H__
#define __PL_ELEMENT_H__

#include "Pl/View.h"

namespace Pl
{
    class Element : public View
    {
        RGBAColor mBackgroundColor;
        
    public:
        
        Element(const Rect& frameRect = Rect());
        
        virtual void setBackgroundColor(const RGBAColor& color);
        
        virtual RGBAColor backgroundColor() const; 
        
        virtual void draw(Drawer& drawer);
    };
}

#endif
