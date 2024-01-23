//!
//! @file Pl/OSX/OSXFont.h
//! @author Luk2010
//! @date 2024/01/23
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_OSX_OSXFONT_H__
#define __PL_OSX_OSXFONT_H__

#include "Pl/Font.h"

namespace Pl
{
    class OSXFont : public Font
    {
        NSFont* mHandle;
        
    public:
        
        OSXFont(NSFont* handle);
        
        virtual double size() const;
        
        virtual double weight() const;
        
        virtual std::string name() const;
        
        virtual std::string family() const;
        
        virtual std::string filePath() const;
        
        virtual bool italic() const;
        
        virtual bool bold() const;
        
        virtual bool underlined() const;
    };
}

#endif
