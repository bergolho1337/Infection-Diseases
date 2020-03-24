set(SOURCE_FILES_ODE ode_solver.h ode_solver.cpp)

ADD_LIBRARY(ode_solver STATIC ${SOURCE_FILES_ODE})

if(NOT MSVC)
    set_property(TARGET ode_solver PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()
