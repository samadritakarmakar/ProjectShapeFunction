function cofactors=cof(matrix)
[r,c]=size(matrix);
mat=zeros(r-1,c-1);
cofactors=mat;
for i=1:r
    for j=1:c
    %Leave out the row and the column of the given i & j repectively.
        mat=[matrix(1:i-1,1:j-1), matrix(1:i-1,j+1:c); ...
             matrix(i+1:r,1:j-1), matrix(i+1:r,j+1:c)];
        cofactors(i,j)=det(mat)*(-1)^(i+j);
    end
end

