#ifndef SHAPEFUNCTIONALLELEMENTTYPES_HPP
#define SHAPEFUNCTIONALLELEMENTTYPES_HPP
#include <armadillo>
#include <vector>
#include "libGmshReader.h"
#include "ShapeFunction.hpp"
using namespace arma;
class ShapeFunctionAllElementTypes
{
public:
    /// Constructor
    ShapeFunctionAllElementTypes(libGmshReader::MeshReader &Mesh)
    {
        //std::vector<ShapeFunction> N(Mesh.NumOfElementTypes);
        ShpFnc=std::vector<ShapeFunction>(Mesh.NumOfElementTypes);
        N=std::vector<mat>(Mesh.NumOfElementTypes);
        for (int i=0;i<Mesh.NumOfElementTypes;i++)
        {
            ShpFnc[i]=ShapeFunction(Mesh,i);
        }
    }

    inline std::vector<mat> GetShapeFunction(mat &GaussPointx)
    {
        for (int i=0; i<ShpFnc.size(); i++)
        {
            N[i]=ShpFnc[i].ShapeFunction::GetShapeFunction(GaussPointx);
        }
        return N;
    }
    inline std::vector<mat> GetShapeFunction(mat &GaussPointx, mat &GaussPointy)
    {
        for (int i=0; i<ShpFnc.size(); i++)
        {
            N[i]=ShpFnc[i].ShapeFunction::GetShapeFunction(GaussPointx, GaussPointy);
        }
        return N;
    }
    inline std::vector<mat> GetShapeFunction(mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        for (int i=0; i<ShpFnc.size(); i++)
        {
            N[i]=ShpFnc[i].ShapeFunction::GetShapeFunction(GaussPointx, GaussPointy, GaussPointz);
        }
        return N;
    }

protected:
std::vector<ShapeFunction> ShpFnc;
std::vector<mat> N;

};
#endif // SHAPEFUNCTIONALLELEMENTTYPES_HPP
