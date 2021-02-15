function [ y ] = nullak( x )

%   >>nullak([0 2 5 7 8 0])
y=0;
n=length(x);
for k=1:n, 
   if x(k)==0, y=y+1;
   end;
end;

end

