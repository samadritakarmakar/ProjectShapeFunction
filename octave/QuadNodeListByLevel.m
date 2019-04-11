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

function [NodeList pos]=QuadNodeListByLevel(x,y,NodeList,pos)
%Points
VertexX=[x(1),x(end)];
VertexY=[y(1),y(end)];
k=1;
limit=2;
for i=1:limit
    for j=1:limit
        NodeList(pos,:)=[VertexX(k),VertexY(i)];
        %k increases as long as k is less than the limit position.
        %As soon as 'i' reaches the limit, k starts decreasing 
        k=k+((i==limit)*(-1)+(k<limit)*(+1));
        pos=pos+1;
    end
end
%Edges
%Edge 1

VertexX=x(2:end-1);
VertexY=y(2:end-1);
addPos=size(VertexX,2);
%if (addPos >1)
    NodeList(pos:pos+addPos-1,:)=[VertexX', y(1)*ones(addPos,1)];
    pos=pos+addPos;
    %Edge 2
    NodeList(pos:pos+addPos-1,:)=[x(end)*ones(addPos,1), VertexY'];
    pos=pos+addPos;
    %Edge 3
    PermMatrix=speye(addPos);
    i=addPos:-1:1;
    PermMatrix=PermMatrix(i,:);
    NodeList(pos:pos+addPos-1,:)=[PermMatrix*VertexX',y(end)*ones(addPos,1)];
    pos=pos+addPos;
    %Edge 4
    NodeList(pos:pos+addPos-1,:)=[x(1)*ones(addPos,1),PermMatrix*VertexY'];
    pos=pos+addPos;
%end

end
