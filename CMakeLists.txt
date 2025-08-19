cmake_minimum_required(VERSION 3.16)
project(bloxoff_engine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bloxoff_engine
    src/engine.cpp
    src/renderer.cpp
)

target_include_directories(bloxoff_engine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(OpenGL REQUIRED)
target_link_libraries(bloxoff_engine PUBLIC OpenGL::GL)

include(GNUInstallDirs)
install(TARGETS bloxoff_engine
    EXPORT bloxoff_engineTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT bloxoff_engineTargets
    FILE bloxoff_engineConfig.cmake
    NAMESPACE bloxoff_engine::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bloxoff_engine
)
