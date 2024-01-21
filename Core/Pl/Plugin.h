//!
//! @file Pl/Plugin.h
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_PLUGIN_H__
#define __PL_PLUGIN_H__

#include "Pl/DynLib.h"

namespace Pl
{
    struct PluginInfos
    {
        std::string name;
        std::string description;
        std::string author;
    };
    
    class Plugin
    {
        Ref < DynLib > mLib;
        
        PluginInfos* mInfos;
        
        bool mInstalled;
        
    public:
        
        Plugin(const std::string& fp);
        
        void install();
        
        void uninstall();
        
        const PluginInfos& infos();
        
        const Ref < DynLib >& dynlib() const;
        
        bool isInstalled() const; 
    };
    
    PLUTON_DEFINE_ERROR(PluginPfnNotFound)
}

#endif
