cmake_minimum_required(VERSION 3.5)

project(CanvasWT LANGUAGES CXX)

set(WT_VERSION 4.10.1)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")



# include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_subdirectory(GameCore)

file(GLOB_RECURSE WtHEADERS ${CMAKE_CURRENT_SOURCE_DIR}/Wt/*.h)
file(GLOB_RECURSE WtSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Wt/*.cpp)
add_executable(CanvasWT ${WtHEADERS} ${WtSOURCES} )


set(Wt_Path C:/Wt_${WT_VERSION}_msvs2022-x64)
set(Wt_DIR ${Wt_Path}/lib/cmake/wt)
FIND_PACKAGE( Wt REQUIRED )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Wt_Path}/lib/cmake/wt")
target_include_directories(CanvasWT PUBLIC "${Wt_Path}/include")
target_include_directories(CanvasWT PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Wt")

target_link_directories(CanvasWT PUBLIC "${Wt_Path}/lib")
target_link_libraries(CanvasWT PRIVATE Wt WtHttp)

target_link_libraries(CanvasWT PRIVATE GameAssets)


target_compile_definitions(CanvasWT PRIVATE DEVELOPMENTMODE )


install(TARGETS CanvasWT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

