function polabra(p,a,b)

x=linspace(a,b,100);
y=polyval(p,x);
plot(x,y);
