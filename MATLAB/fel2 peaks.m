x=linspace(-2,2,100);
y=x;
[xx,yy]=meshgrid(x,y);
z=peaks(xx,yy);
contour(x,y,z)
