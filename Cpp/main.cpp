#include <iostream>
#include "cof.hpp"
#include "GmshNodeListGen.h"
#include <armadillo>
#include "FindCoeffTriangle.hpp"
#include "FindCoeffQuad.hpp"
#include "FindCoeffHexahedral.hpp"
#include "FindCoeffLine.hpp"
#include "FindCoeffTertrahedral.hpp"
#include <string>
#include "libGmshReader.h"
using namespace arma;
int main(int argc, char *argv[])
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
    //mat Mat3;
    //mat NodeList3=GmshNodeListHexahedral(order);
    //BuildHexahedralMatrix(order, NodeList3.col(0),NodeList3.col(1), NodeList3.col(2), NodeList3.n_rows, Mat3);
    //cout<<Mat3*FindCoeffHexadedral(order).t();
    //mat Mat4;
    //mat NodeList4=GmshNodeListLine(order);
    //BuildLineMatrix(order, NodeList4.col(0), NodeList4.n_rows, Mat4);
    //cout<<Mat4*FindCoeffLine(order).t();
    //mat Mat5;
    //mat NodeList5=GmshNodeListTetrahedral(order);
    //BuildTetrahedralMatrix(order, NodeList5.col(0),NodeList5.col(1), NodeList5.col(2), NodeList5.n_rows, Mat5);
    //cout<<Mat5*FindCoeffTetrahedral(order).t();
    if(argc==1 || argc>3)
    {
        std::cout<<"Usage: ./ProjectShapeFunction <.msh Filename> <Dimension>\n";
    }
    else
    {
        std::string FileName(argv[1]);
        int Dimension=*argv[2]-'0';
        //cout<<"File Name= "<<FileName<<"\n";
        //cout<<"Dimension= "<<Dimension<<"\n";
        libGmshReader::MeshReader Mesh(FileName, Dimension);
        //cout<<Mesh.NodalCoordinates;
    }
    return 0;
}
