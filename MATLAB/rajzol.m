function rajzol

x=[-1 2 3 4 7];
y=[5 3 1 0 -1];
plot(x,y,'ro')


p=polyfit(x,y,1);
title(p);
x1=linspace(-1,8,100);
y1=polyval(p,x1);
hold on
plot(x1,y1);
hold off



