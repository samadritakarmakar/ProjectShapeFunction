// Automatically translated using m2cpp 2.0 on 2019-04-15 21:08:17

#ifndef NUMOFTETRANODES_M_HPP
#define NUMOFTETRANODES_M_HPP

int NumOfTetraNodes(int order)
{
  int NumOfNodes ;
  NumOfNodes = (order*(order+1)*(2*order+1))/12+3*(order*(order+1))/4+order+1 ;
  return NumOfNodes ;
}
#endif
