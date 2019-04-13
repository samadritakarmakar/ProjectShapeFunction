// Automatically translated using m2cpp 2.0 on 2019-04-11 23:33:14

#ifndef BUILDTRIANGLEMATRIX_M_HPP
#define BUILDTRIANGLEMATRIX_M_HPP


#include <armadillo>
#include <algorithm>
using namespace arma ;

void BuildTriangleMatrix(int order, mat x, mat y,  const int& NumOfNodes, mat& Mat)
{
  int i, j, lengthx, pos ;
  lengthx = std::max(x.n_rows,x.n_cols) ;
  Mat = zeros(lengthx, NumOfNodes) ;
  Mat.col(0) = ones(lengthx,1) ;
  pos = 0 ;
  for (i=1; i<=order; i++)
  {
    pos = (i*(i+1))/2.0-1 ;
    Mat.col(pos+1) = arma::pow(x, i) ;
    Mat.col(pos+2) = arma::pow(y, i) ;
    for (j=1; j<=i-1; j++)
    {
      Mat.col(pos+2+j) = (arma::pow(x, j))%(arma::pow(y, (i-j))) ;
    }
  }
}
#endif
