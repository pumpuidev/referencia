function [ L,D,U ] = felbont( A )
%   Detailed explanation goes here
D=diag(diag(A));
L=tril(A)-D;
U=triu(A)-D;
end

