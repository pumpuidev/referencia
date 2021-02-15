function M=zoldmatrix(n)

M=zeros(n);
for i=1:n
    for j=1:n
         M(i,j)=(j-i)+1;
    end
end