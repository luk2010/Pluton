//!
//! @file Pl/CharAttributes.h
//! @author Luk2010
//! @date 2024/01/27
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_CHARATTRIBUTES_H__
#define __PL_CHARATTRIBUTES_H__

#include "Pl/Platform.h"
#include "Pl/Font.h"

namespace Pl
{
    struct CharAttributes
    {
        RGBAColor foregroundColor = RGBAColor(0.0, 0.0, 0.0);
        RGBAColor backgroundColor = RGBAColor(0.0, 0.0, 0.0, 0.0);
        FontRef font;
    };
    
    namespace CharAttribute
    {
        constexpr const uint32_t ForegroundColor = 1 << 0;
        constexpr const uint32_t BackgroundColor = 1 << 1;
        constexpr const uint32_t Font = 1 << 2;
    }
    
    typedef uint32_t CharAttributesMask;
}

#endif
