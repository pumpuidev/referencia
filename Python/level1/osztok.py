x = input("Irj be egy szamot:")

print x, "osztoi:"
osztok=[1,x]
temp=[]
for i in range(2,(x/2)+1) :
    if x % i == 0 :
        temp += [i]   # temp = temp + [i]
osztok[1:1] = temp
print osztok
