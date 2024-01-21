//!
//! @file Pl/Element.cpp
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Element.h"

namespace Pl
{
    Element::Element(const Rect& frameRect): View(frameRect), mBackgroundColor(0.0, 0.0, 0.0, 0.0)
    {
        
    }
    
    void Element::setBackgroundColor(const RGBAColor& color)
    {
        mBackgroundColor = color;
        setNeedsDraw(true);
    }
    
    RGBAColor Element::backgroundColor() const
    {
        return mBackgroundColor;
    }
    
    void Element::draw(Drawer& drawer)
    {
        auto rect = bounds();
        
        if (mBackgroundColor.alpha > 0.0)
        {
            drawer.setFillColor(mBackgroundColor);
            drawer.fill(rect, 0.0);
        }
    }
}
