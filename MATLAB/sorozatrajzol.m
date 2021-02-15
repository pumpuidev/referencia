% sorozat fv

m=35;
a=zeros(m,1);
for n=1:m
    a(n)= (1+(1/n))^(n+1);
end

plot(1:m,a,'o')