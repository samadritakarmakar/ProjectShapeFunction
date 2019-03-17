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

%This function returns the list of nodes in a Complete Triangle
%as per the passed order of the Shape Function.
%The sequence of the listing of the nodes is per the sequence gernerated by Gmsh.

function NodeList=GmshNodeListTriangle(order)
x=linspace(0,1, order+1);
y=linspace(0,1, order+1);
x=x(2:end-1);
y=y(2:end-1);
PermMatrix=speye(order-1);
PermMatrix=PermMatrix(end:-1:1,:);
%Vertex
NodeList=[0,0 ; 1,0; 0,1];
%Edges
NodeList=[NodeList; x',zeros(order-1,1)]; %Edge 1
NodeList=[NodeList; PermMatrix*x', y']; %Edge 2
NodeList=[NodeList; zeros(order-1,1), PermMatrix*y']; %Edge 3
%Surface
for i=1:order-2
    NodeList=[NodeList; x(1:end-i)', y(i)'*ones(order-(i+1),1)];
end
plot(NodeList(:,1),NodeList(:,2),'o');
