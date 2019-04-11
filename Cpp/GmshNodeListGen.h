#ifndef GMSHNODELISTGEN_H
#define GMSHNODELISTGEN_H
#include "gmsh.h"
#include <armadillo>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace arma;

void GetNodeList_4_1_Element(const std::string &FolderName, const std::string &FileName,
                             const int &order, const int &dim, mat &NodeList);
mat GmshNodeListTriangle(int order);
mat GmshNodeListQuadrilateral(int order);
mat GmshNodeListTetrahedral(int order);
mat GmshNodeListHexahedral(int order);

mat GmshNodeListTriangle(int order)
{

    int dim=2;
    std::string FolderName="BaseGeom/";
    std::string FileName="Triangle";
    mat NodeList;
    GetNodeList_4_1_Element(FolderName, FileName, order, dim, NodeList);
    return NodeList;
}
mat GmshNodeListQuadrilateral(int order)
{

    int dim=2;
    std::string FolderName="BaseGeom/";
    std::string FileName="Quadrilateral";
    mat NodeList;
    GetNodeList_4_1_Element(FolderName, FileName, order, dim, NodeList);
    return NodeList;
}

mat GmshNodeListTetrahedral(int order)
{
    int dim=3;
    std::string FolderName="BaseGeom/";
    std::string FileName="Tetrahedral";
    mat NodeList;
    GetNodeList_4_1_Element(FolderName, FileName, order, dim, NodeList);
    return NodeList;
}

mat GmshNodeListHexahedral(int order)
{
    int dim=3;
    std::string FolderName="BaseGeom/";
    std::string FileName="Hexahedral";
    mat NodeList;
    GetNodeList_4_1_Element(FolderName, FileName, order, dim, NodeList);
    return NodeList;
}

void GetNodeList_4_1_Element(const std::string &FolderName, const std::string &FileName,
                             const int &order, const int &dim, mat &NodeList)
{
    gmsh::initialize();
    std::string FileOpen=FolderName+FileName+".geo";
    std::ifstream fileExists(FileOpen);
    if (fileExists)
    {
        gmsh::open(FileOpen);
        cout<<FileOpen<<" has been opened to find Base Geometry Nodes\n";
    }
    else
    {
        cout<<FileOpen<<" could not be found. Exiting!\n";
        throw ;
    }
    gmsh::vectorpair dimTags;
    gmsh::model::getEntities(dimTags, 0);
    //Comment this out to debug and find out the dimention tags
    /*
    cout<<"Dimension tags are,\n";
    for (int i=0;i<dimTags.size();i++)
    {
        cout<<dimTags[i].first<<" "<<dimTags[i].second<<"\n";
    }*/
    //gmsh::model::mesh::setSize(dimTags, 3.0);
    gmsh::model::mesh::generate(dim);
    gmsh::model::mesh::setOrder(order);
    std::vector<double> coord;
    std::vector<double> parametricCoord;
    std::vector<std::vector<int>> nodeTags2;
    std::vector<int> elementTypes;
    std::vector<std::vector<int>> elementTags;
    gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags2,dim,-1);
    //std::cout<<"Size of node list in element"<<nodeTags2[0].size()<<"\n"; //To debug the size of nodes in one element.
    NodeList.set_size(nodeTags2[0].size(), dim);
    for (int i=0; i<nodeTags2[0].size(); i++)
    {
        gmsh::model::mesh::getNode(nodeTags2[0][i],coord,parametricCoord);
        for (int j=0; j<dim; j++)
        {
           NodeList(i,j)=coord[j];
        }
    }
    gmsh::write(FolderName+FileName+".msh");
    gmsh::finalize();
}
#endif // GMSHNODELISTGEN_H
