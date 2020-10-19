
//Feladat: Másodfokú egyenlet megoldása
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a,b,c,d,x;
    bool van;
    cout<<"Masodfoku egyenlet megoldasa! (a*x*x+b*x+c=0)"<<endl<<endl;
    do {
        cout<<"A masodfoku tag egyutthatoja (a=)";
        cin>>a;
    }while (a==0);          //az elõfeltétel szerint a<>0
    cout<<"Az elsofoku tag egyutthatoja: (b=)";
    cin>>b;                 //b értékére nincs kikötés
    cout<<"A konstans erteke (c=)";
    cin>>c;                  //c értékére nincs kikötés

    d=b*b-4*a*c;             //diszkriminans erteke
    van=d>0;

    if (van){
        x=(-b+sqrt(d))/(2*a);
        cout<<"Van ket gyok, az egyik: "<<x;
    }
    else{
        cout<<"Nincs ket gyok";
    }

    return 0;
}
