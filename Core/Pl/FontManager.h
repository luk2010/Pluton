//!
//! @file Pl/FontManager.h
//! @author Luk2010
//! @date 2024/01/22
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_FONTMANAGER_H__
#define __PL_FONTMANAGER_H__

#include "Pl/FontLoader.h"
#include "Pl/Manager.h"
#include "Pl/Singleton.h"

namespace Pl
{
    PLUTON_DEFINE_ERROR(CannotLoadFont)
    
    class FontManager : public Singleton < FontManager >
    {
        Manager < Font > mFonts;
        
        std::map < std::string, Ref < FontLoader > > mLoaders;
        
    public:
        
        void addLoader(const std::string& loaderName, const Ref < FontLoader >& loader);
        
        void removeLoader(const std::string& loaderName);
        
        void removeLoader(const Ref < FontLoader >& loader);
        
        void clearLoaders();
        
        Ref < FontLoader > findLoader(const std::string& name) const;
        
        std::map < std::string, Ref < FontLoader > > loaders() const;
        
        Ref < Font > loadWithFamily(const std::string& familyName,
                                    double size,
                                    bool italic = false,
                                    bool bold = false,
                                    double weight = 1.0);
        
        Ref < Font > loadWithFile(const std::string& filePath,
                                  double size,
                                  bool italic = false,
                                  bool bold = false,
                                  double weight = 1.0);
        
        std::vector < Ref < Font > > fonts() const;
    };
}

#endif
