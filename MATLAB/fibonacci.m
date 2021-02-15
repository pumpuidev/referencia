function fibonacci(n)

i=1;
j=1;
disp(i);
disp(j);
for k = 1:(n-2)
    x=i+j;
    disp(x)
    if i>j
          j=x;
    else 
        i=x;
    end
end
end
    
   