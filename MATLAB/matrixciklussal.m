% matrix

function M=matrixciklussal(n)

M=zeros(n);
for i=1:n
    for j=1:n
        M(i,j)=i;
    end
end