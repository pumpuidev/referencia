function l = kereses(v)
%|| alt gr+w
%&& altgr+c
l=false;
i=1;
while ~l && i<=length(v)
    
    if v(i)==0
        l=true;
    end
    i=i+1;
end