function illeszt

x = [-3 -2 0 1 3];
y = [-4 -2 0 2 4];
plot(x,y,'ro')

p = polyfit(x,y,1);

xf = linspace(-11,11,100);
yf = polyval(p,xf);
hold on
plot(xf,yf)
hold off