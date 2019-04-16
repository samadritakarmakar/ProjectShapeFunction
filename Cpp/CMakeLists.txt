cmake_minimum_required(VERSION 2.8)

project(GmshNodeListGen)

set(CMAKE_CXX_FLAGS "-O3")
find_package(Armadillo REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/libGmshReader/GmshApi/")
add_subdirectory(libGmshReader/GmshApi/)

set (PreInstalled armadillo blas lapack)

set (InternalDev GmshNodeListGen.h cof.hpp
    BuildTriangleMatrix.hpp FindCoeffTriangle.hpp NumOfTriNodes.hpp
    FindCoeffQuad.hpp NumOfQuadNodes.hpp BuildQuadMatrix.hpp
    BuildHexahedralMatrix.hpp FindCoeffHexahedral.hpp NumOfHexaNodes.hpp
    BuildTetrahedralMatrix.hpp FindCoeffTertrahedral.hpp NumOfTetraNodes.hpp)

add_executable(${PROJECT_NAME} main.cpp ${InternalDev})
target_link_libraries (${PROJECT_NAME} ${PreInstalled}  ${CMAKE_SOURCE_DIR}/libGmshReader/GmshApi/libgmsh.a)

set (COPY_FILES BaseGeom)
foreach(loop_var ${COPY_FILES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${loop_var} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach(loop_var)
