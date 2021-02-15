function db=szamlalas(v)

db=0;
for i=1:length(v)
    if v(i)>0 db=db+1;
    end
end