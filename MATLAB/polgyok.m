function [ y ] = polgyok( x )
%keres egy polinomot
%   >>polgyok(5)
s=-5:0.1:5;
y=polyvar(p,x);
[y,s] = polyval(p,x,s)
plot(x,y,'o');
end

