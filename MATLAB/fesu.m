function m=fesu(j,k)

h=length(j)*2
m=zeros(1,h);


for i=1:length(j)
    m(i)=j(i);
end
for i=1:length(k)
    m(length(j)+i)=k(i);
end
