x=linspace(-2,2,100);
y=x;
[xx,yy]=meshgrid(x,y);
z=xx+yy-xx.^2;
contour(x,y,z)
