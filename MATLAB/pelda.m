x=linspace(-3*pi,3*pi,100);
y=x;
[xx,yy]=meshgrid(x,y);
zz=cos(xx).*sin(yy);
surf(x,y,zz)
shading interp  