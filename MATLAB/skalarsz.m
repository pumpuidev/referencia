function m=skalarsz(v1,v2)

osszeg=0;
n=length(v1);
for i=1:n
    osszeg=osszeg+v1(i)*v2(i);
end
m=osszeg;
end