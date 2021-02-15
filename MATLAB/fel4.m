n=input('Kérem n értékét: ');
x0=1; x1=1;
for k=2:n, seged=x0+x1;
           x0=x1;
           x1=seged;
end; 
disp(x1);
