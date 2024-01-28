//!
//! @file Pl/U32String.h
//! @author Luk2010
//! @date 2024/01/26
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_U32STRING_H__
#define __PL_U32STRING_H__

#include "Pl/Platform.h"

namespace Pl
{
    class U32String
    {
        U32Buffer mBuffer;
        
    public:
        
        U32String(const char* cStr = NULL);
        
        size_t length() const;
        
        size_t size() const;
        
        U32Char* data();
        
        const U32Char* data() const;
        
        size_t findFirst(const U32String& rhs) const;
        
        size_t findLast(const U32String& rhs) const;
        
        size_t findNext(size_t from, const U32String& rhs) const;
        
        void insert(size_t index, const U32String& str);
        
        void append(const U32String& rhs);
        
        void prepend(const U32String& rhs);
        
        void erase(size_t index, size_t count = 1);
        
        std::string utf8() const;
        
        friend std::ostream& operator << (std::ostream& os, const Pl::U32String& str);
    };
}

#endif
