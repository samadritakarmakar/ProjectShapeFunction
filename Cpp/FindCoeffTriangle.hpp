// Automatically translated using m2cpp 2.0 on 2019-04-11 23:33:14

#ifndef FINDCOEFFTRIANGLE_M_HPP
#define FINDCOEFFTRIANGLE_M_HPP
#include "GmshNodeListGen.h"
#include "cof.hpp"
#include "BuildTriangleMatrix.hpp"
#include "NumOfTriNodes.hpp"
#include <armadillo>
using namespace arma ;

mat FindCoeffTriangle(int order)
{
  mat CoeffMatrix, CofMatrix, Mat, NodeList, x, y ;
  int NumOfNodes;
  NodeList = GmshNodeListTriangle(order) ;
  x = NodeList.col(0) ;
  y = NodeList.col(1) ;
  NumOfNodes = NumOfTriNodes(order) ;
  BuildTriangleMatrix(order, x, y, NumOfNodes, Mat) ;
  CofMatrix = cof(Mat) ;
  CoeffMatrix = speye(NumOfNodes,NumOfNodes)*cof(Mat)/det(Mat) ;
  return CoeffMatrix ;
}
#endif
