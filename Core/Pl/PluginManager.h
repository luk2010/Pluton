//!
//! @file Pl/PluginManager.h
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_PLUGINMANAGER_H__
#define __PL_PLUGINMANAGER_H__

#include "Pl/Plugin.h"
#include "Pl/Manager.h"
#include "Pl/Singleton.h"

namespace Pl
{
    class PluginManager : public Manager < Plugin >,
                          public Singleton < PluginManager >
    {
    public:
        
        Ref < Plugin > load(const std::string& fp);
        
        std::vector < Ref < Plugin > > loadDirectory(const std::string& dirp, bool recursive = false);
        
    protected:
        
        void onAdd(const Ref < Plugin >& plugin);
        
        void onRemove(const Ref < Plugin >& plugin);
    };
}

#endif
