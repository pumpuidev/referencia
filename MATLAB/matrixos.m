function A=matrixos(n,k)

A=ones(n);
A=A.*k
A=tril(A);
A=triu(A);
