 %x^3 -2 =0

a=1; fa = 1^3-2;
b=2; fb = 2^3-2;
while (b-a) > 0.0001
  c=(a+b)/2; fc = c^3 -2;
  disp([a c b])
  if fa*fc < 0 
      b=c; fb = fc;
  else
     a=c; fa = fc; 
  end
end
