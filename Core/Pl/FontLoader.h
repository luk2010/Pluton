//!
//! @file Pl/FontLoader.h
//! @author Luk2010
//! @date 2024/01/22
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_FONTLOADER_H__
#define __PL_FONTLOADER_H__

#include "Pl/Font.h"

namespace Pl
{
    class FontLoader
    {
    public:
        
        virtual ~FontLoader() = default;
        
        virtual Ref < Font > createWithFamily(const std::string& family,
                                              double size,
                                              bool italic = false,
                                              bool bold = false,
                                              double weight = 1.0) = 0;
        
        virtual Ref < Font > createWithFile(const std::string& filePath,
                                            double size,
                                            bool italic = false,
                                            bool bold = false,
                                            double weight = 1.0) = 0;
    };
}

#endif 
