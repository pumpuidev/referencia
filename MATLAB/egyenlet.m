function egyenlet(a,b)

if (a==0) && (b==0) 
    disp('v�gtlen megold�s')
end
 if (a==0) && ~(b==0)   
     disp('nincs megold�s')
 end
 if ~(a==0) && ~(b==0)
     disp(-b/a)
 end
       