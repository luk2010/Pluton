//!
//! @file Pl/Text.h
//! @author Luk2010
//! @date 2024/01/27
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_TEXT_H__
#define __PL_TEXT_H__

#include "Pl/U32String.h"
#include "Pl/CharAttributes.h"

namespace Pl
{
    class Text
    {
        U32String mString;
        
        std::vector < CharAttributes > mAttribs;
        
    public:
        
        Text(const U32String& str = U32String(), const CharAttributes& defAttribs = {});
        
        void setString(const U32String& string);
        
        const U32String& string() const;
        
        void setAttributes(const Range& range, const CharAttributes& attributes);
        
        const CharAttributes& attributesAt(size_t index) const;
        
        size_t length() const;
        
        const U32Char* data() const;
        
        void setAttributes(const Range& range, const CharAttributesMask mask, const CharAttributes& attributes);
    };
}

#endif
