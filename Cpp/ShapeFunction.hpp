#ifndef SHAPEFUNCTION_H
#define SHAPEFUNCTION_H
#include "libGmshReader.h"
#include <armadillo>
#include <string>
#include "FindCoeffLine.hpp"
#include "FindCoeffTriangle.hpp"
#include "FindCoeffQuad.hpp"
#include "FindCoeffTertrahedral.hpp"
#include "FindCoeffHexahedral.hpp"
using namespace arma;
class ShapeFunction
{
public:
    mat (ShapeFunction::*FunctionPtr)( mat&, mat&, mat&);
    /// Default Constructor. Remember to call 'ShapeFunction(libGmshReader::MeshReader &Mesh, const int& ElementType)'
    ShapeFunction()
    {
        //----Do Nothing-----
    }
    /// Constructor. Here type of element is checked and the needed Function pointer is assigned.
    ShapeFunction(libGmshReader::MeshReader &Mesh, const int& ElementType)
    {
        int i=ElementType;
        order=Mesh.order[ElementType];
        if(Mesh.GmshElementNameOnly[i].compare("Line")==0)
        {
            FunctionPtr=&ShapeFunction::LineShapeFuntion;
            Coefficient=FindCoeffLine(order).t();
        }
        else if(Mesh.GmshElementNameOnly[i].compare("Triangle")==0)
        {
            FunctionPtr=&ShapeFunction::TriangleShapeFunction;
            Coefficient=FindCoeffTriangle(order).t();
        }
        else if(Mesh.GmshElementNameOnly[i].compare("Quadrilateral")==0)
        {
            FunctionPtr=&ShapeFunction::QuadShapeFunction;
            Coefficient=FindCoeffQuad(order).t();
        }
        else if(Mesh.GmshElementNameOnly[i].compare("Tetrahedron")==0)
        {
            FunctionPtr=&ShapeFunction::TetrahedralShapeFunction;
            Coefficient=FindCoeffTetrahedral(order).t();
        }
        else if(Mesh.GmshElementNameOnly[i].compare("Hexahedron")==0)
        {
            FunctionPtr=&ShapeFunction::HexahedralShapeFunction;
            Coefficient=FindCoeffHexadedral(order).t();
        }
        else
        {
            std::cout<<"Shape Function "<<Mesh.GmshElementNameOnly[i]<<" is not supported!!\n";
            throw;
        }
    }
    ///For 1D Shape Functions
    inline mat GetShapeFunction( mat &GaussPointx)
    {
        mat GaussPointz={0}; mat GaussPointy={0};
        return (this->*FunctionPtr)( GaussPointx, GaussPointy, GaussPointz);
    }
    ///For 2D Shape Functions
    inline mat GetShapeFunction( mat &GaussPointx, mat &GaussPointy)
    {
        mat GaussPointz={0};
        return (this->*FunctionPtr)( GaussPointx, GaussPointy, GaussPointz);
    }
    ///For 3D Shape Functions
    inline mat GetShapeFunction( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        return (this->*FunctionPtr)( GaussPointx, GaussPointy, GaussPointz);
    }


private:
    inline mat LineShapeFuntion( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        mat Matrx;
        BuildLineMatrix(order, GaussPointx, NumOfLineNodes(order), Matrx);
        mat N=(Matrx*Coefficient).t();
        return N;
    }
    inline mat TriangleShapeFunction( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        mat Matrx;
        int NumOfNodes=NumOfTriNodes(order);
        BuildTriangleMatrix(order, GaussPointx, GaussPointy, NumOfNodes, Matrx);
        mat N=(Matrx*Coefficient).t();
        return N;
    }
    inline mat QuadShapeFunction( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        mat Matrx;
        int NumOfNodes=NumOfQuadNodes(order);
        BuildQuadMatrix(order, GaussPointx, GaussPointy, NumOfNodes, Matrx);
        mat N=(Matrx*Coefficient).t();
        return N;
    }

    inline mat TetrahedralShapeFunction( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        mat Matrx;
        int NumOfNodes=NumOfTetraNodes(order);
        BuildTetrahedralMatrix(order, GaussPointx, GaussPointy, GaussPointz, NumOfNodes, Matrx);
        mat N=(Matrx*Coefficient).t();
        return N;
    }

    inline mat HexahedralShapeFunction( mat &GaussPointx, mat &GaussPointy, mat &GaussPointz)
    {
        mat Matrx;
        int NumOfNodes=NumOfHexaNodes(order);
        BuildHexahedralMatrix(order, GaussPointx, GaussPointy, GaussPointz, NumOfNodes, Matrx);
        mat N=(Matrx*Coefficient).t();
        return N;
    }
    mat Coefficient;
    int order;

};

#endif // SHAPEFUNCTION_H
