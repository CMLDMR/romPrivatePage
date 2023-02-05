cmake_minimum_required(VERSION 3.5)

project(CanvasWT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_executable(CanvasWT ${HEADERS} ${SOURCES} )


include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(Wt_Path C:/Wt_4.9.1_msvs2022_x64)
set(Wt_DIR ${Wt_Path}/lib/cmake/wt)
FIND_PACKAGE( Wt REQUIRED )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Wt_Path}/lib/cmake/wt")
target_include_directories(CanvasWT PUBLIC "${Wt_Path}/include")
target_link_directories(CanvasWT PUBLIC "${Wt_Path}/lib")
target_link_libraries(CanvasWT PRIVATE Wt WtHttp)
set_target_properties(CanvasWT PROPERTIES LINK_FLAGS "/ignore:4251")


install(TARGETS CanvasWT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
