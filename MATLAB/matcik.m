function matcik(n)

A=ones(n);
for i=1:n
    for j=1:n
        if j>=i A(i,j)=(j-i)+1
            else A(i,j)=(i-j)+1
        end
    end
end
disp(A);
end