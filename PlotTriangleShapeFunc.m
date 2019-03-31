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

%This part of the code is responsible to gernerate the points within x[0,1] & y[0,1]
clear;
close all;
order=3
CoeffMatrix=FindCoeffTriangle(order);
x=0:.0125:1;
y=x;
z=zeros(length(y),length(x));
NumOfNodes=NumOfTriNodes(order);

for j=1:NumOfNodes    
    for i=1:length(x)
        Mat=BuildTriangleMatrix(order, x(i)*ones(length(y),1), y', NumOfNodes);
        z(:,i)=Mat*CoeffMatrix(j,:)';
        z(end-(i-2):end,i)=nan; %Clearing up data not part of the triangle.
    end
    figure(j+1);
    m=surf(x,y,z);
    set(m,'edgecolor','none');
end
