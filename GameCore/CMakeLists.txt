cmake_minimum_required(VERSION 3.5)

project(CanvasWT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")



add_library(GameAssets SHARED
    GameAssets_global.h
    GlobalVariable.h
    item.h item.cpp
    building/building.h building/building.cpp
    building/MainBuilding.h building/MainBuilding.cpp )


target_compile_definitions(GameAssets PRIVATE GameAssets_LIBRARY)
target_include_directories(GameAssets PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

