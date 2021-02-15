function [ Sn ] = sorossz( n )

%  >>sorossz(20)
n=20;
Sn=1/n(n+1);
while (20>=n), Sn=Sn+1; 
    Sn=1/n(n+1);
end;

