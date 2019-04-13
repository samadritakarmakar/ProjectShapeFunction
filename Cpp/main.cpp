#include <iostream>
#include "cof.hpp"
#include "GmshNodeListGen.h"
#include <armadillo>
#include "FindCoeffTriangle.hpp"
using namespace arma;
int main()
{
    //std::cout<<"List of Coordinates in a Triangle\n"<<GmshNodeListTriangle(3);
    //std::cout<<"List of Coordinates in a Quadrilateral\n"<<GmshNodeListQuadrilateral(3);
    //std::cout<<"List of Coordinates in a Tetrahedral\n"<<GmshNodeListTetrahedral(3);
    //std::cout<<"List of Coordinates in a Hexahedral\n"<<GmshNodeListHexahedral(2);
    //mat A;
    //A << 1 << 2 << 1<< 5 <<endr << 3 << 4 << 3<< 2 <<endr<<5 <<6 <<7<< 4 <<endr<< 4 << 3 << 2 << 9<<endr;
    //std::cout<<cof(A);
    int order =4;
    mat NodeList=GmshNodeListTriangle(order);
    mat Mat;
    BuildTriangleMatrix(order,NodeList.col(0),NodeList.col(1),NodeList.col(0).n_rows, Mat);
    cout<<Mat*FindCoeffTriangle(order).t();
    return 0;
}
