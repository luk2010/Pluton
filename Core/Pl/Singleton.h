//!
//! @file Pl/Singleton.h
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_SINGLETON_H__
#define __PL_SINGLETON_H__

#include "Pl/Platform.h"

namespace Pl
{
    template < class T >
    class Singleton
    {
    public:
        
        static T& Get()
        {
            static T instance;
            return instance;
        }
        
    protected:
        
        Singleton() {}
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        
        Singleton& operator = (const Singleton&) = delete;
        Singleton& operator = (Singleton&&) = delete;
        
        ~Singleton() {}
    };
}

#endif
