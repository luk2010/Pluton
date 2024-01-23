//!
//! @file Pl/OSX/OSXFontLoader.mm
//! @author Luk2010
//! @date 2024/01/23
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/OSXFontLoader.h"
#include "Pl/OSX/OSXFont.h"

namespace Pl
{
    Ref < Font > OSXFontLoader::createWithFamily(const std::string& family,
                                                 double size,
                                                 bool italic,
                                                 bool bold,
                                                 double weight)
    {
        NSFontManager* manager = [NSFontManager sharedFontManager];
        NSFontTraitMask mask = 0;
        
        if (italic) mask |= NSFontItalicTrait;
        if (bold) mask |= NSFontBoldTrait;
        
        NSFont* font = [manager fontWithFamily:[NSString stringWithUTF8String:family.data()]
                                        traits:mask
                                        weight:weight
                                          size:size];
        
        if (!font)
            return nullptr;
        
        return Make < OSXFont >(font);
    }
    
    Ref < Font > OSXFontLoader::createWithFile(const std::string &filePath, double size, bool italic, bool bold, double weight)
    {
        return nullptr;
    }
}
