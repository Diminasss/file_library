cmake_minimum_required(VERSION 3.10)
project(file_library_project VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_library(filelib
    lib/filelib.cpp
    lib/exceptions.cpp
)

target_include_directories(filelib PUBLIC lib)

add_executable(main_exec main.cpp)

target_link_libraries(main_exec PRIVATE filelib)
