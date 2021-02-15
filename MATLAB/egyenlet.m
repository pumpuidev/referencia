function egyenlet(a,b)

if (a==0) && (b==0) 
    disp('végtlen megoldás')
end
 if (a==0) && ~(b==0)   
     disp('nincs megoldás')
 end
 if ~(a==0) && ~(b==0)
     disp(-b/a)
 end
       