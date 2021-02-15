function [x] = megoldo2(a,b,c)
%x=-b+-sqrt(b^2-4*a*c)/2*a
%d=b*b-4ac
d = sqrt(b^2 - 4*a*c);
x(1) = ( -b + d ) / (2*a);
x(2) = ( -b - d ) / (2*a);
end

