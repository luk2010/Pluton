//!
//! @file Pl/OSX/OSXFont.mm
//! @author Luk2010
//! @date 2024/01/23
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/OSXFont.h"

namespace Pl
{
    OSXFont::OSXFont(NSFont* handle): mHandle(handle)
    {
        
    }
    
    double OSXFont::size() const
    {
        return mHandle.pointSize;
    }
    
    double OSXFont::weight() const
    {
        NSFontManager* manager = [NSFontManager sharedFontManager];
        
        return [manager weightOfFont:mHandle];
    }
    
    std::string OSXFont::name() const
    {
        return [[mHandle displayName] UTF8String];
    }
    
    std::string OSXFont::family() const
    {
        return [[mHandle familyName] UTF8String];
    }
    
    std::string OSXFont::filePath() const
    {
        return std::string();
    }
    
    bool OSXFont::italic() const
    {
        NSFontManager* manager = [NSFontManager sharedFontManager];
        NSFontTraitMask traits = [manager traitsOfFont:mHandle];
        
        return traits & NSFontItalicTrait;
    }
    
    bool OSXFont::bold() const
    {
        NSFontManager* manager = [NSFontManager sharedFontManager];
        NSFontTraitMask traits = [manager traitsOfFont:mHandle];
        
        return traits & NSFontBoldTrait;
    }
    
    bool OSXFont::underlined() const
    {
        return false;
    }
}
