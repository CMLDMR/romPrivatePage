cmake_minimum_required(VERSION 3.5)

project(CanvasWT LANGUAGES CXX)

set(WT_VERSION 4.9.1)


#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Qt/Tools/ccache-4.7.4-windows-x86_64")


#find_program(CCACHE_FOUND ccache)
#if(CCACHE_FOUND)
#    message("CCACHE FOUND")
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
#endif(CCACHE_FOUND)


#if(NOT CCACHE_FOUND)
#    message("CCACHE NOT FOUND")
#endif(NOT CCACHE_FOUND)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_executable(CanvasWT ${HEADERS} ${SOURCES} )


include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(Wt_Path C:/Wt_${WT_VERSION}_msvs2022_x64)
set(Wt_DIR ${Wt_Path}/lib/cmake/wt)
FIND_PACKAGE( Wt REQUIRED )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Wt_Path}/lib/cmake/wt")
target_include_directories(CanvasWT PUBLIC "${Wt_Path}/include")
target_link_directories(CanvasWT PUBLIC "${Wt_Path}/lib")
target_link_libraries(CanvasWT PRIVATE Wt WtHttp)
set_target_properties(CanvasWT PROPERTIES LINK_FLAGS "/ignore:4251")


install(TARGETS CanvasWT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


if(WIN32)
  add_definitions("/wd4251")
  add_definitions("/wd4267")
  add_definitions("/wd4275")
endif(WIN32)
