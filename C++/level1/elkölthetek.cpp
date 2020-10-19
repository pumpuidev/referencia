#include <iostream>
#include <cstdlib>
/*Prorok Ernest
Filspa
hbv
ernest.prorok@gmail.com */
using namespace std;

int main()
{
    int osszeg;
    cout<<"mennyit keresek: ";
    cin>>osszeg;

    if(osszeg<0){
        cout<<"ez nem valos adat";
        exit(1);
    }

    osszeg=osszeg % 5000;
    cout<<osszeg<<"\n";

    return 0;
}
