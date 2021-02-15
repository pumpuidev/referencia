%paraboloid

xf=linspace(-1,1,101);
yf=linspace(0,3*pi,101);
[x,y]=meshgrid(xf,yf);
z=(x.^2).*sin(y);
surf(x,y,z)
%colorbar;
colormap pink
axis equal
%mesh, contourf,surf,