cmake_minimum_required(VERSION 3.10)
project(CHIP-8)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(CHIP-8 src/main.cpp
	src/CHIP-8/CHIP-8.cpp
	src/CHIP-8/Memory.cpp
	src/CHIP-8/Display.cpp
	src/CHIP-8/Stack.cpp
)
target_include_directories(CHIP-8 PRIVATE include)

set(SDL_STATIC ON)
add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
target_link_libraries(CHIP-8 PRIVATE SDL3::SDL3-static)
