//!
//! @file Pl/Text.cpp
//! @author Luk2010
//! @date 2024/01/27
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Text.h"

namespace Pl
{
    Text::Text(const U32String& string, const CharAttributes& defAttribs):
    mString(string)
    {
        if (string.length())
            mAttribs.resize(string.length(), defAttribs);
    }
    
    void Text::setString(const U32String& string)
    {
        mString = string;
        mAttribs.clear();
        
        if (mString.length())
            mAttribs.resize(string.length());
    }
    
    const U32String& Text::string() const
    {
        return mString;
    }
    
    void Text::setAttributes(const Range& range, const CharAttributes& attributes)
    {
        size_t end = range.length ? range.start + range.length : mString.length();
        
        for (size_t i = range.start; i < mString.length() && i < end; ++i)
            mAttribs[i] = attributes;
    }
    
    const CharAttributes& Text::attributesAt(size_t index) const
    {
        return mAttribs[index];
    }
    
    size_t Text::length() const
    {
        return mString.length();
    }
    
    const U32Char* Text::data() const
    {
        return mString.data();
    }
    
    void Text::setAttributes(const Range& range, const CharAttributesMask mask, const CharAttributes& attributes)
    {
        size_t end = range.length ? range.start + range.length : mString.length();
        
        for (size_t i = range.start; i < mString.length() && i < end; ++i)
        {
            auto& attrib = mAttribs[i];
            
            if (mask & CharAttribute::ForegroundColor)
                attrib.foregroundColor = attributes.foregroundColor;
            if (mask & CharAttribute::BackgroundColor)
                attrib.backgroundColor = attributes.backgroundColor;
            if (mask & CharAttribute::Font)
                attrib.font = attributes.font;
        }
    }
}
