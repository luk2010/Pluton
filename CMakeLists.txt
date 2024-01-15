cmake_minimum_required(VERSION 3.12)

project(
    Pluton
    VERSION "0.0.1"
    LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(PLUTON_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(Core)
add_subdirectory(Modules)
add_subdirectory(Plugins)
add_subdirectory(Examples)