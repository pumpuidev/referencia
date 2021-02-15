x=linspace(-1,1,15);
y=x;
[xx,yy]=meshgrid(x,y);
zz=(xx.^3)+(xx.*yy.^2)-(yy.^3);
contour(x,y,z)