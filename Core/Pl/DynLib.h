//!
//! @file Pl/DynLib.h
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_DYNLIB_H__
#define __PL_DYNLIB_H__

#include "Pl/Platform.h"

namespace Pl
{
    class DynLib
    {
        PLUTON_DYNLIB_HANDLE mHandle;
        
        std::string mFilePath;
        
    public:
        
        DynLib(const std::string& fp);
        
        ~DynLib();
        
        PLUTON_DYNLIB_HANDLE handle() const;
        
        const std::string& filePath() const;
        
        void* find(const std::string_view& symbol) const;
    };
    
    PLUTON_DEFINE_ERROR(DlOpenFailed)
    PLUTON_DEFINE_ERROR(DlSymFailed)
}

#endif
