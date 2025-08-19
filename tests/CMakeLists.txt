include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(bloxoff_engine PRIVATE --coverage)
        target_link_libraries(bloxoff_engine PRIVATE --coverage)
    endif()
endif()


enable_testing()
add_executable(my_tests test_main.cpp)
target_link_libraries(my_tests gtest_main)
add_test(NAME MyTests COMMAND my_tests)
