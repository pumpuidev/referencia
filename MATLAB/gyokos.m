function e=gyokos(p)

gy=roots(p);
e=0;
for i=1:length(gy)
        e = e+ gy(i)^2;
end

    