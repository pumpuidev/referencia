function w=rendez(v)

w = v;
n=length(v);

for i= 1:n-1 %hanyadik menet
    for j = i:n-i %hanyadik osszehasonlitas
      if w(j) > w(j+1) 
          %csere
          seged=w(j);
          w(j)=w(j+1);
          w(j+1)=seged;
      end
      
    end
end

