//!
//! @file Pl/Plugin.cpp
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Plugin.h"

namespace Pl
{
    Plugin::Plugin(const std::string& fp)
    {
        mLib = Make < DynLib >(fp);
        mInfos = NULL;
        mInstalled = false;
    }

    void Plugin::install() 
    {
        typedef void(*PLPluginInstallPfn)(void);

        if (mInstalled)
            return;
        
        PLPluginInstallPfn fn = (PLPluginInstallPfn) mLib->find(PLUTON_PLUGIN_INSTALL_PFN);
        
        if (!fn)
            throw PluginPfnNotFound("Pl::Plugin: install function not found in library '", mLib->filePath(), "'.");
        
        fn();
        mInstalled = true;
    }
    
    void Plugin::uninstall()
    {
        if (!mInstalled)
            return;
        
        typedef void(*PLPluginUninstallPfn)(void);
        PLPluginUninstallPfn fn = (PLPluginUninstallPfn) mLib->find(PLUTON_PLUGIN_UNINSTALL_PFN);
        
        if (!fn)
            throw PluginPfnNotFound("Pl::Plugin: uninstall function not found in library '", mLib->filePath(), "'.");
        
        fn();
        mInstalled = false;
    }
    
    const PluginInfos& Plugin::infos()
    {
        if (mInfos)
            return *mInfos;
        
        typedef PluginInfos*(*PLPluginGetInfosPfn)(void);
        PLPluginGetInfosPfn fn = (PLPluginGetInfosPfn) mLib->find(PLUTON_PLUGIN_GETINFOS_PFN);
        
        if (!fn)
            throw PluginPfnNotFound("Pl::Plugin: GetInfos function not found in library '", mLib->filePath(), "'.");
        
        mInfos = fn();
        return *mInfos;
    }
    
    const Ref < DynLib >& Plugin::dynlib() const
    {
        return mLib;
    }
    
    bool Plugin::isInstalled() const
    {
        return mInstalled;
    }
}
