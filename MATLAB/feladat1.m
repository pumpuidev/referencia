function [  ] = feladat1( n1,n2 )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
x=linspace(-10,10,50);
y=-(n1/n2)*x;
yy=(n2/n1)*x;
plot(x,y,x,yy);
grid on
axis equal
title('meroleges egyenesek')
text(1,2,'valami')
end

