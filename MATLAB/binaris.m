function [ y ] = binaris( x )
%kerek egy kettes szamrendszerbeli szamot
%   >>binaris(101)
egyes=0;
nullas=0;
if x==1, egyes=egyes+1;
    elseif x==0 nullas=nullas+1;
else y=input('hibauzenet');
end
    
y=input(egyes,' és ',nullas);    
end;

