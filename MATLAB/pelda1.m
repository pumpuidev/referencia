x1=linspace(-pi,pi,100);
x2=linspace(-pi/2,pi/2,100);
x2=x2(2:99);
x3=linspace(0,pi,100);
x3=x3(2:99);

y1=sin(x1);
y2=cos(x1);
y3=tan(x2);
y4=cot(x3);

subplot(2,2,1); 
plot(x1,y1); 
axis([-pi,pi,-1,1]); 
title('sin(x)');

subplot(2,2,2); 
plot(x1,y2); 
axis([-pi,pi,-1,1]); 
title('cos(x)');

subplot(2,2,3); 
plot(x2,y3); 
axis([-pi/2,pi/2,-10,10]); 
title('tg(x)');

subplot(2,2,4); 
plot(x3,y4); 
axis([0,pi,-10,10]); 
title('ctg(x)');
