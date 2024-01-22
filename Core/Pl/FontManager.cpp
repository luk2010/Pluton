//!
//! @file Pl/FontManager.cpp
//! @author Luk2010
//! @date 2024/01/22
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/FontManager.h"

namespace Pl
{
    void FontManager::addLoader(const std::string& loaderName, const Ref<FontLoader>& loader)
    {
        mLoaders[loaderName] = loader;
    }
    
    void FontManager::removeLoader(const std::string& loaderName)
    {
        auto it = mLoaders.find(loaderName);
        
        if (it != mLoaders.end())
            mLoaders.erase(it);
    }
    
    void FontManager::removeLoader(const Ref<FontLoader>& loader)
    {
        auto it = std::find_if(mLoaders.begin(), mLoaders.end(), [&loader](const auto& pair)
        {
            return pair.second == loader;
        });
        
        if (it != mLoaders.end())
            mLoaders.erase(it);
    }
    
    void FontManager::clearLoaders()
    {
        mLoaders.clear();
    }
    
    Ref < FontLoader > FontManager::findLoader(const std::string& name) const
    {
        auto it = mLoaders.find(name);
        
        if (it == mLoaders.end())
            return nullptr;
        
        return it->second;
    }
    
    std::map < std::string, Ref < FontLoader > > FontManager::loaders() const
    {
        return mLoaders;
    }
    
    Ref < Font > FontManager::loadWithFamily(const std::string& familyName, double size, bool italic, bool bold, double weight)
    {
        Ref < Font > font;
        
        mFonts.forEach([&](const auto& rhs)
        {
            if (rhs->family() == familyName &&
                rhs->size() == size &&
                rhs->italic() == italic &&
                rhs->bold() == bold &&
                rhs->weight() == weight)
            {
                font = rhs;
                return false;
            }
            
            return true;
        });
        
        if (font)
            return font;
        
        for (auto& loader : mLoaders)
        {
            font = loader->loadWithFamily(familyName, size, italic, bold, weight);
            
            if (font)
            {
                mFonts.add(font);
                return font;
            }
        }
        
        throw CannotLoadFont("Pl::FontManager: Cannot load font '", familyName, "'.");
    }
    
    Ref < Font > FontManager::loadWithFile(const std::string& filePath, double size, bool italic, bool bold, double weight)
    {
        Ref < Font > font;
        
        mFonts.forEach([&](const auto& rhs)
        {
            if (rhs->filePath() == filePath &&
                rhs->size() == size &&
                rhs->italic() == italic &&
                rhs->bold() == bold &&
                rhs->weight() == weight)
            {
                font = rhs;
                return false;
            }
            
            return true;
        });
        
        if (font)
            return font;
        
        for (auto& loader : mLoaders)
        {
            font = loader->loadWithFile(filePath, size, italic, bold, weight);
            
            if (font)
            {
                mFonts.add(font);
                return font;
            }
        }
        
        throw CannotLoadFont("Pl::FontManager: Cannot load font '", filePath, "'.");
    }
    
    std::vector < Ref < Font > > FontManager::fonts() const
    {
        return mFonts.values();
    }
}
