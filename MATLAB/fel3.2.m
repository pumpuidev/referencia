fi=linspace(0,6*pi,100); % 2 helyett 6 pi - 3szor tekeredik
r=linspace(0,1,100);
r=fliplr(r);
r=fliplr(r); %masodik fliplr
polar(fi,r);
