
//Feladat: Egy magyar szó egyik magánhangzójának megadása
//Kiválasztási tétel alapján - magyar szavakban biztosan van legalább egy magánhagzó!!!
////indextartomany transzformációja az 1..N intervallumról a 0..N-1 tartomanyra
#include <iostream>
#include <string>
using namespace std;

const int maxHossz=100;
void beolvas(string &Szo);
void egyikmaganhangzo(const string Szo, int& S);
bool maganhangzo_e(const char kar);
bool vanMaganhangzo(const string Szo);
int main()
{   string Szo;
    int S;
    cout<<"Melyik a szo egyik maganhangzoja?"<<endl<<endl;
    beolvas(Szo);
    egyikmaganhangzo(Szo,S);
    cout << "A(z) '" <<Szo<<"' egyik maganhangzoja a(z) "<<S<<". karakter, "<<Szo[S]<<endl;
    return 0;
}
void beolvas(string &Szo){
    do{
    cout<<"Kerem a magyar szot (ekezetes betut ne hasznaljon):";
    cin>>Szo;
    } while(!vanMaganhangzo(Szo));
}
void egyikmaganhangzo(const string Szo, int &S){
    int i=0;
    while (!maganhangzo_e(Szo[i])){
        ++i;
    }
    S=i;
}
bool maganhangzo_e(const char kar){
    const int mghDb=10;                     //magánhangzók száma
    const char mgh[10]={'a','e','o','u','i','A','E','O','U','I'};   //elõforduló magánhangzók - ékezetes betûket, most nem ábrázoljuk
    int i=0;
    while ((i<mghDb)&&(mgh[i]!=kar)){
        ++i;
    }
    return (i<mghDb);
}
bool vanMaganhangzo(const string Szo){
    int i=0;
    int Hossz=Szo.length();
    while ((i<Hossz)&&(!(maganhangzo_e(Szo[i])))){
        ++i;
    }
    return i<Hossz;
}
