function A = ablak(n,m)

A=ones(n,m);
A(2:n-1,2:m-1)=0;
