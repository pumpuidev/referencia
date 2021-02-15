function [e,h] = maximum(v)

n = length(v);
h = 1;
e = v(1);
for i = 2:n
    if v(i)> e
        h = i;
        e = v(h);
    end
end