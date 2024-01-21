//!
//! @file Pl/PluginManager.cpp
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/PluginManager.h"

namespace Pl
{
    Ref < Plugin > PluginManager::load(const std::string& fp)
    {
        auto filePath = std::filesystem::path(fp).replace_extension(PLUTON_DYNLIB_EXT).string();
        Ref < Plugin > plugin;
        
        forEach([&plugin, &filePath](const Ref < Plugin >& rhs)
        {
            if (filePath == rhs->dynlib()->filePath())
                plugin = rhs;
        });
        
        if (plugin)
            return plugin;
    
        plugin = Make < Plugin >(filePath);
            
        add(plugin);
        
        return plugin;
    }
    
    std::vector < Ref < Plugin > > PluginManager::loadDirectory(const std::string& dirp, bool recursive)
    {
        std::vector < Ref < Plugin > > results;
        
        if (recursive)
        {
            for (std::filesystem::directory_entry const& entry : std::filesystem::recursive_directory_iterator(dirp))
            {
                if (entry.path().extension() != PLUTON_DYNLIB_EXT)
                    continue;
                
                try
                {
                    auto plugin = load(entry.path().string());
                    results.push_back(plugin);
                }
                catch (const PluginPfnNotFound& error)
                {
                    std::cout << "Pl::PluginManager: Cannot load file '" << entry << "' because it does not "
                    << "seem to be a Plugin." << std::endl;
                    continue;
                }
            }
        }
        
        else
        {
            for (std::filesystem::directory_entry const& entry : std::filesystem::directory_iterator(dirp))
            {
                if (entry.path().extension() != PLUTON_DYNLIB_EXT)
                    continue;
                
                try
                {
                    auto plugin = load(entry.path().string());
                    results.push_back(plugin);
                }
                catch (const PluginPfnNotFound& error)
                {
                    std::cout << "Pl::PluginManager: Cannot load file '" << entry << "' because it does not "
                    << "seem to be a Plugin." << std::endl;
                    continue;
                }
            }
        }
        
        return results;
    }
    
    void PluginManager::onAdd(const Ref < Plugin >& plugin)
    {
        plugin->install();
    }
    
    void PluginManager::onRemove(const Ref < Plugin >& plugin)
    {
        plugin->uninstall();
    }
}
