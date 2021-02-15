function db=nagyszam(v)

db=0;
for i=1:length(v)
    if v(i) > 10
        db=db+1;
    end
end
