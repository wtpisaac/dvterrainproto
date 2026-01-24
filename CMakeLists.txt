cmake_minimum_required(VERSION 3.31)

project("dvterrainproto")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendored/raylib)

add_executable(
    dvterrainproto 
    src/main.c 
    src/panes/pane_viewport.c 
    src/panes/pane_panel.c
    src/input/input.c
    src/core/core.c
    src/render/render.c
)

target_link_libraries(dvterrainproto PRIVATE raylib)

