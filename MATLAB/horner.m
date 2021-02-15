function [y]=horner(p,x)
n=length(p);
y=p(1);
for k=2:n, y=y*x+p(k);
end;
