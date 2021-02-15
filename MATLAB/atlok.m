% A=tridiag(-1,2,-1), 10x10-es
atlo1=ones(1,10)*2;
atlo2=-ones(1,9);
A=diag(atlo1)+diag(atlo2,-1)+diag(atlo2,1);
