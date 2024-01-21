cmake_minimum_required(VERSION 3.12)

project(
    Pluton
    VERSION "0.0.1"
    LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(PLUTON_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(PLUTON_PLUGIN_INSTALL_PFN
    "PLPluginInstall"
    CACHE STRING 
    "The name of the function used to install a Pl::Plugin.")

set(PLUTON_PLUGIN_UNINSTALL_PFN
    "PLPluginUninstall"
    CACHE STRING 
    "The name of the function used to uninstall a Pl::Plugin.")

set(PLUTON_PLUGIN_GETINFOS_PFN
    "PLPluginGetInfos"
    CACHE STRING 
    "The name of the function that returns a Pl::PluginInfos structure.")

message(STATUS "PLUTON_PLUGIN_INSTALL_PFN = ${PLUTON_PLUGIN_INSTALL_PFN}")
message(STATUS "PLUTON_PLUGIN_UNINSTALL_PFN = ${PLUTON_PLUGIN_UNINSTALL_PFN}")
message(STATUS "PLUTON_PLUGIN_GETINFOS_PFN = ${PLUTON_PLUGIN_GETINFOS_PFN}")

add_subdirectory(Core)
add_subdirectory(Modules)
add_subdirectory(Plugins)
add_subdirectory(Examples)