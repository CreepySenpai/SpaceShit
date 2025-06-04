cmake_minimum_required(VERSION 4.0.1)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_C_STANDARD 23)

project(SpaceShit VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SpaceShit main.cpp)

file(GLOB STD_CORE_MODULE ${CMAKE_SOURCE_DIR}/module/std/std.cppm)

file(GLOB SPACE_SHIT_CORE_MODULE ${CMAKE_SOURCE_DIR}/module/Creepy/Core/*.cppm)
file(GLOB SPACE_SHIT_CORE_IMPL ${CMAKE_SOURCE_DIR}/src/Creepy/Core/*.cpp)

file(GLOB SPACE_SHIT_WINDOW_MODULE ${CMAKE_SOURCE_DIR}/module/Creepy/Window/*.cppm)
file(GLOB SPACE_SHIT_WINDOW_WIN64_IMPL ${CMAKE_SOURCE_DIR}/src/Creepy/Window/Win64/*.cpp)

file(GLOB SPACE_SHIT_GAME_MODULE ${CMAKE_SOURCE_DIR}/module/Creepy/Game/*.cppm)
file(GLOB SPACE_SHIT_GAME_IMPL ${CMAKE_SOURCE_DIR}/src/Creepy/Game/*.cpp)

file(GLOB SPACE_SHIT_GRAPHICS_MODULE ${CMAKE_SOURCE_DIR}/module/Creepy/Graphics/*.cppm)
file(GLOB SPACE_SHIT_GRAPHICS_IMPL ${CMAKE_SOURCE_DIR}/src/Creepy/Graphics/*.cpp)

add_library(SpaceShitLib STATIC)

target_sources(SpaceShitLib PUBLIC FILE_SET CXX_MODULES FILES ${STD_CORE_MODULE} ${SPACE_SHIT_CORE_MODULE} ${SPACE_SHIT_WINDOW_MODULE} ${SPACE_SHIT_GAME_MODULE} ${SPACE_SHIT_GRAPHICS_MODULE})
target_sources(SpaceShitLib PRIVATE ${SPACE_SHIT_CORE_IMPL} ${SPACE_SHIT_WINDOW_WIN64_IMPL} ${SPACE_SHIT_GAME_IMPL} ${SPACE_SHIT_GRAPHICS_IMPL})

target_include_directories(SpaceShitLib PUBLIC ${CMAKE_SOURCE_DIR}/module)

target_link_directories(SpaceShitLib PUBLIC ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(SpaceShitLib PUBLIC stdc++exp d3d11 d3dcompiler)

add_compile_definitions(SpaceShitLib PUBLIC -DNOMINMAX -DWIN32_LEAN_AND_MEAN)

target_link_libraries(SpaceShit PUBLIC SpaceShitLib)