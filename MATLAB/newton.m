%newton módszer x^2-2=0

x = 2;
for i=1:1000
    x=x/2 +1/x;
    format long
    disp(x)
end
