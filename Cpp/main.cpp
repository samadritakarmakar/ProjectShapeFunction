#include <iostream>
#include "GmshNodeListGen.h"
using namespace std;

int main()
{
    std::cout<<"List of Coordinates in a Triangle\n"<<GmshNodeListTriangle(3);
    std::cout<<"List of Coordinates in a Quadrilateral\n"<<GmshNodeListQuadrilateral(3);
    std::cout<<"List of Coordinates in a Tetrahedral\n"<<GmshNodeListTetrahedral(3);
    std::cout<<"List of Coordinates in a Hexahedral\n"<<GmshNodeListHexahedral(2);
    return 0;
}
