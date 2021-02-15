function g=szorxmegegy(p)

gy=roots(p);
q=p(1)*poly([gy; -1])
