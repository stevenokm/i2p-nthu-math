cmake_minimum_required(VERSION 3.14)
project(hello_test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  gtest_main
)

add_executable(
  sample2_unittest
  sample2_unittest.cc
  sample2.cc
)
target_link_libraries(
  sample2_unittest
  gtest_main
)

add_executable(
  sample4_unittest
  sample4_unittest.cc
  sample4.cc
)
target_link_libraries(
  sample4_unittest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(sample2_unittest)
gtest_discover_tests(sample4_unittest)