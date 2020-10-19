
//Feladat:  Derékszögû háromszög-e
#include <iostream>

using namespace std;

int main()
{   double x,y,z;
    bool lehet;
    cout<<"Szerkesztheto-e derekszogu haromszog az alabbi adatokbol?"<<endl;
    cout<<"A vizsgalat az x*x+y*y=z*z egyenlet felhasznalasaval tortenik. "<<endl;

    do {
        cout<<"Kerem a haromszog elso oldalanak hosszat! (x=)";
        cin>>x;
    }while (x<=0);  //az oldal hossza az elõfeltétel miatt pozitív

    do {
        cout<<"Kerem a haromszog masodik oldalanak hosszat! (y=)";
        cin>>y;
    }while (y<=0);  //az oldal hossza az elõfeltétel miatt pozitív

    do {
        cout<<"Kerem a haromszog harmadik oldalanak hosszat! (z=)";
        cin>>z;
    }while (z<=0);  //az oldal hossza az elõfeltétel miatt pozitív

    lehet=(x*x+y*y==z*z);

    if (lehet){
        cout<<"A megadott oldalak derekszogu haromszoget alkotnak. "<<endl;
    }
    else{
        cout<<"A megadott oldalak nem alkotnak derekszogu haromszoget. "<<endl;
    }

    return 0;
}
