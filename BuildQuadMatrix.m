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

function Mat=BuildQuadMatrix(order, x, y, NumOfNodes)
lengthx=length(x);
Mat=zeros(lengthx, NumOfNodes);
Mat(:,1)=ones(lengthx,1);
pos=2;
for i=1:order
Mat(:,pos)=x.^i; %Builds x; x^2;... etc
Mat(:,pos+1)=y.^i; %Builds y; y^2;... etc
pos=pos+2;
    for j=1:order
        Mat(:,pos)=x.^i.*y.^j; %Builds xy; xy, xy^2, x^2y, x^2y^2;.. etc
        pos=pos+1;
    end
end
