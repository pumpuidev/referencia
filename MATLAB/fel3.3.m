function [ A ] = fel3( n )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
if n<4 , diag('hibas n') , A=0;
else
   A=diag([1:n]);
   A=A-diag(ones(1,n-1),1);
   A=A-diag(ones(1,n-2),-2);
end
end
