cmake_minimum_required(VERSION 3.10)
project(lab_3)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_library(lib1 SHARED lib1.cpp)
add_library(lib2 SHARED lib2.cpp)

add_executable(main1 linking.cpp)
target_link_libraries(main1 lib1)

add_executable(main2 runtime.cpp)