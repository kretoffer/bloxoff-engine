set(PROJECT_NAME bloxoff_engine)

cmake_minimum_required(VERSION 3.15)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Connect Conan toolchain
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake OPTIONAL RESULT_VARIABLE _toolchain_included)
if(NOT _toolchain_included)
    message(FATAL_ERROR "Conan toolchain not found. Run 'conan install . --output-folder=build --build=missing'")
endif()

# Add src
add_executable(${PROJECT_NAME} src/main.cpp
    src/Application.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC includes)

# Install requirements Conan
find_package(glfw3 REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
    spdlog::spdlog
)

