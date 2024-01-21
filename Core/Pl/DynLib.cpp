//!
//! @file Pl/DynLib.cpp
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/DynLib.h"

namespace Pl
{
    DynLib::DynLib(const std::string& fp)
    {
        auto filePath = std::filesystem::path(fp).replace_extension(PLUTON_DYNLIB_EXT);
        
        if (!std::filesystem::exists(filePath))
            throw FileNotFound("Pl::DynLib: File '", filePath, "' not found.");
        
        mFilePath = filePath;
        mHandle = PLUTON_DYNLIB_DLOPEN(filePath.c_str());
        
        if (!mHandle)
            throw DlOpenFailed("Pl::DynLib: DLOPEN failed with file '", filePath, "'.");
    }
    
    DynLib::~DynLib()
    {
        if (mHandle)
            PLUTON_DYNLIB_DLCLOSE(mHandle);
    }
    
    PLUTON_DYNLIB_HANDLE DynLib::handle() const
    {
        return mHandle;
    }
    
    const std::string& DynLib::filePath() const
    {
        return mFilePath;
    }
    
    void* DynLib::find(const std::string_view& symbol) const
    {
        return PLUTON_DYNLIB_DLSYM(mHandle, symbol.data());
    }
}
