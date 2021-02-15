t = [0:0.01:4*pi]
a = sin(t);
b = cos(t);

plot(t,a,'r',t,b,'b')
%plot(t,b)
axis([-1 14 -1.2 1.2]) 