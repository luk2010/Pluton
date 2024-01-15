
add_executable(
    HelloWorld 
    main.cpp)

target_link_libraries(
    HelloWorld 
    PUBLIC 
    Pluton)

target_include_directories(
    HelloWorld 
    PUBLIC 
    ${CMAKE_SOURCE_DIR}/Core)

install(
    TARGETS HelloWorld
    RUNTIME DESTINATION ${PLUTON_INSTALL_DIR}/bin)
