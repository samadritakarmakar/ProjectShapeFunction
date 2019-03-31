%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Copyright (C) Samadrita Karmakar (samadritakarmakar@gmail.com)
%    This program is free software: you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation, either version 3 of the License, or
%    (at your option) any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program.  If not, see <https://www.gnu.org/licenses/>.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%This function returns the list of nodes in a Complete Quadrilateral
%as per the passed order of the Shape Function.
%The sequence of the listing of the nodes is per the sequence gernerated by Gmsh.


function NodeList=GmshNodeListQuad(order)
%clear;
%order=5
x=linspace(-1,1, order+1);
y=linspace(-1,1, order+1);
%Size of Matrix
NumOfNodes=NumOfQuadNodes(order);
NodeList=zeros(NumOfNodes,2);
pos=1;
%here it keeps on reducing the range for which are taken as input
%ex. if x=[-1, -0.5, 0, 0.5, 1] in the 1st loop, then it would 
%be x=[-0.5, 0, 0.5] in the second loop. But it would only run 
%2 times, since (order+1)/2=2 where order=4. This maskes the %center node at (0,0) the last node
for i=1:floor((order+1)/2)
    [NodeList pos]=QuadNodeListByLevel(x(i:end-(i-1)),y(i:end-(i-1)),NodeList,pos);
end

plot(NodeList(:,1),NodeList(:,2),'o')
