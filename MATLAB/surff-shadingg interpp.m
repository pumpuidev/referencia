x=linspace(-10,10,50);
y=x;
[xx,yy]=meshgrid(x,y);
zz=xx.*yy;
surf(xx,yy,zz)
shading interp  