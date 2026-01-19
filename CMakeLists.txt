cmake_minimum_required(VERSION 3.31)

project("dvterrainproto")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendored/raylib)

add_executable(dvterrainproto src/main.c)

target_link_libraries(dvterrainproto PRIVATE raylib)

