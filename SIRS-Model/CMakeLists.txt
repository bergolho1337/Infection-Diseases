cmake_minimum_required(VERSION 3.0.1)
project(SIRS)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

#~ find_package(VTK REQUIRED)
#~ include(${VTK_USE_FILE})

ADD_SUBDIRECTORY(src/options)
ADD_SUBDIRECTORY(src/ini_parser)
ADD_SUBDIRECTORY(src/utils)
ADD_SUBDIRECTORY(src/ode_solver)

ADD_EXECUTABLE(SIRS src/main.cpp)

ADD_DEPENDENCIES(SIRS options ini_parser utils ode_solver)

TARGET_LINK_LIBRARIES(SIRS options ini_parser utils ode_solver dl m)
