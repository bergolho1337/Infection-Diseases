set(SOURCE_FILES_SOLVER solver.h solver.cpp)

ADD_LIBRARY(solver STATIC ${SOURCE_FILES_SOLVER})

if(NOT MSVC)
    set_property(TARGET solver PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()
