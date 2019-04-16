#include <iostream>
#include "cof.hpp"
#include "GmshNodeListGen.h"
#include <armadillo>
#include "FindCoeffTriangle.hpp"
#include "FindCoeffQuad.hpp"
#include "FindCoeffHexahedral.hpp"
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
    int order =1;
    //mat NodeList=GmshNodeListTriangle(order);
    //mat Mat;
    //BuildTriangleMatrix(order,NodeList.col(0),NodeList.col(1),NodeList.col(0).n_rows, Mat);
    //cout<<Mat*FindCoeffTriangle(order).t();*/
    //mat NodeList2=GmshNodeListQuadrilateral(order);
    //mat Mat2;
    //BuildQuadMatrix(order, NodeList2.col(0), NodeList2.col(1), NodeList2.n_rows, Mat2);
    //cout<<Mat2*FindCoeffQuad(order).t();
    mat Mat3;
    mat NodeList3=GmshNodeListHexahedral(order);
    BuildHexahedralMatrix(order, NodeList3.col(0),NodeList3.col(1), NodeList3.col(2), NodeList3.n_rows, Mat3);
    cout<<Mat3*FindCoeffHexadedral(order).t();
    return 0;
}
