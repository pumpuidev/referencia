%y = linspace(-0.5*pi,0.5*pi,50);
%z = linspace(-1,1,50);
y = linspace(-pi/2,pi/2,50);
a = sin(y);
%b = asin(z);
%plot(y,a,'r',z,b,'b')
plot(y,a,'r',a,y,'b')
legend('sin','arcsin')



