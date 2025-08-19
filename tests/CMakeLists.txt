include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(my_tests test_main.cpp)
target_link_libraries(my_tests gtest_main)
add_test(NAME MyTests COMMAND my_tests)
