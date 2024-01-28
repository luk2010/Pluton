//!
//! @file Pl/Font.h
//! @author Luk2010
//! @date 2024/01/22
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_FONT_H__
#define __PL_FONT_H__

#include "Pl/Platform.h"

namespace Pl 
{
    namespace FontWeight
    {
        constexpr const double Thin = 100.0;
        constexpr const double UltraLight = 200.0;
        constexpr const double Light = 300.0;
        constexpr const double Regular = 400.0;
        constexpr const double Medium = 500.0;
        constexpr const double SemiBold = 600.0;
        constexpr const double Bold = 700.0;
        constexpr const double UltraBold = 800.0;
        constexpr const double Heavy = 900.0;
        constexpr const double UltraBlack = 950.0;
    }
    
    class Font
    {
    public:
        
        virtual ~Font() = default;
        
        virtual double size() const = 0;
        
        virtual double weight() const = 0;
        
        virtual std::string name() const = 0;
        
        virtual std::string family() const = 0;
        
        virtual std::string filePath() const = 0;
        
        virtual bool italic() const = 0;
        
        virtual bool bold() const = 0;
        
        virtual bool underlined() const = 0;
    };
    
    typedef Ref < Font > FontRef;
}

#endif 
