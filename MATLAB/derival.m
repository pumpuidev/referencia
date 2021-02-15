function g=derival(p)

n=length(p);
q=zeros(1,n-1);
for i=1:n-1
    q(i)= p(i)*(n-i)
end