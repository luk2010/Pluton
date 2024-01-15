
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

file(GLOB PLUTON_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/Pl/*.h
                         ${CMAKE_CURRENT_BINARY_DIR}/config.h)
file(GLOB PLUTON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Pl/*.cpp)

add_library(
    Pluton 
    SHARED 
    ${PLUTON_HEADERS}
    ${PLUTON_SOURCES})

target_include_directories(
    Pluton 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(
    Pluton 
    PRIVATE 
    "PLUTON_BUILD_LIB=1")

if(APPLE AND NOT IOS)

    find_library(PLUTON_LIB_COCOA Cocoa REQUIRED)

    file(GLOB PLUTON_OSX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Pl/OSX/*.h
                                 ${CMAKE_CURRENT_SOURCE_DIR}/Pl/OSX/*.mm)

    target_link_libraries(
        Pluton 
        PUBLIC 
        ${PLUTON_LIB_COCOA})

    target_sources(
        Pluton 
        PRIVATE 
        ${PLUTON_OSX_SOURCES})

endif()

install(
    TARGETS Pluton 
    LIBRARY DESTINATION ${PLUTON_INSTALL_DIR})
