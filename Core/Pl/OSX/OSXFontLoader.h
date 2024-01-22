//!
//! @file Pl/OSX/OSXFontLoader.h
//! @author Luk2010
//! @date 2024/01/22
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_OSXFONTLOADER_H__
#define __PL_OSXFONTLOADER_H__

#include "Pl/FontLoader.h"

namespace Pl
{
    class OSXFontLoader : public FontLoader
    {
    public:
        
        virtual Ref < Font > createWithFamily(const std::string& family,
                                              double size,
                                              bool italic,
                                              bool bold,
                                              double weight);
        
        virtual Ref < Font > createWithFile(const std::string& filePath,
                                            double size,
                                            bool italic,
                                            bool bold,
                                            double weight);
    };
}

#endif
