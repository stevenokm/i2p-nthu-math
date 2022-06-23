# Example: Unit Test for Vector & Matrix in Binary File (class ver.)

## `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.14)
project(lecture18_ex)

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
  lecture18_unittest
  lecture18_unittest.cpp
)
target_link_libraries(
  lecture18_unittest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(lecture18_unittest)
```

## `lecture18_ex.h`

``` c++
{{#include example_cpp/lecture18_ex.h}}
```

## `lecture18_ex.cpp`

``` c++
{{#include example_cpp/lecture18_ex.cpp}}
```

## `lecture18_unittest.cpp`

``` c++
{{#include example_cpp/lecture18_unittest.cpp}}
```

## Result

``` console
Running main() from C:\Users\stevenokm\googletest\build\_deps\googletest-src\googletest\src\gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from Vector_3D
[ RUN      ] Vector_3D.Init
[       OK ] Vector_3D.Init (0 ms)
[ RUN      ] Vector_3D.WriteFile
[       OK ] Vector_3D.WriteFile (6 ms)
[ RUN      ] Vector_3D.ReadFile
[       OK ] Vector_3D.ReadFile (1 ms)
[----------] 3 tests from Vector_3D (15 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (22 ms total)
[  PASSED  ] 3 tests.
```