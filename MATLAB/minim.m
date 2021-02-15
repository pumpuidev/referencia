function [m,ind]=minim(x)
n=length(x);
ind=1;
m=x(1);
for k=1:n-1, if x(k+1)< m, m=x(k+1);
                           ind=k+1;
           end;
end;
