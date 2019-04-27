cmake_minimum_required(VERSION 2.8)

project(ProjectShapeFunction)

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(Armadillo REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories ("${PROJECT_SOURCE_DIR}/libGmshReader/GmshApi/")
add_subdirectory(libGmshReader/GmshApi/)
include_directories ("${PROJECT_SOURCE_DIR}/libGmshReader/")
add_subdirectory(libGmshReader/)
include_directories ("${PROJECT_SOURCE_DIR}/ShapeFunction/LagrangeShapeFunction/")
add_subdirectory(ShapeFunction/LagrangeShapeFunction/)

set (PreInstalled armadillo blas lapack)

set (InternalDev ShapeFunction.hpp ShapeFunctionAllElementTypes.hpp)

set (PreDev libGmshReader GmshApi LagrangeShapeFunction)

set (PreInstalled armadillo lapack openblas superlu)

add_executable(${PROJECT_NAME} main.cpp ${InternalDev})
target_link_libraries (${PROJECT_NAME} ${PreDev} ${PreInstalled} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_SOURCE_DIR}/libGmshReader/GmshApi/libgmsh.a)

set (COPY_FILES BaseGeom)
foreach(loop_var ${COPY_FILES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${loop_var} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach(loop_var)
