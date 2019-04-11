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

function [Mat NumOfNodes]=BuildTriangleMatrix(order, x, y, NumOfNodes)
lengthx=length(x);
Mat=zeros(lengthx, NumOfNodes);
Mat(:,1)=ones(lengthx,1);
pos=0;
for i=1:order
    pos=i*(i+1)/2;
    Mat(:,pos+1)=x.^i; %x^2, x^3, ... etc
    Mat(:,pos+2)=y.^i; %y^2, y^3, ... etc
    for j=1:i-1
        Mat(:,pos+2+j)=(x.^j).*(y.^(i-j)); % xy or; xy2,x2y; or; xy^3, x^2y^2, x^3y, ... etc
    end
end
