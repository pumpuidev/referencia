function terbeli

xf = linspace(0,2*pi,40);
yf = linspace(0,2*pi,40);
[x,y] = meshgrid(xf,yf);
z = cos(x) * cos(y);
figure(1); surf(x,y,z)
figure(2); contourf(x,y,z)
