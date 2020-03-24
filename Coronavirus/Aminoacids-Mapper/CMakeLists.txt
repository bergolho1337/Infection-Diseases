cmake_minimum_required(VERSION 3.0.1)
project(Aminoacids-Mapper)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/solver)

ADD_EXECUTABLE(Aminoacids-Mapper src/main.cpp)

ADD_DEPENDENCIES(Aminoacids-Mapper solver)

TARGET_LINK_LIBRARIES(Aminoacids-Mapper solver dl m)
