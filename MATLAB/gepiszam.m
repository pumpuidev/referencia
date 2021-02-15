%
% gepiszam kirajzolja az M(4,-3,3)-ben talalhato gepi szamokat.
%

a=[8 9 10 11 12 13 14 15]*2^(-4);
y=[a./8,a./4,a./2,a,a*2,a*4,a*8];
%axis([-8,8,-8,8]);
hold off;
plot([-y,y],[-y,y],'.');
title('M(4,-3,3)\{0} szamai'),
xlabel('Valos szam'),ylabel('Potty jelzi, ha van gepi szam')