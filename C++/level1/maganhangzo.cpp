
//Feladat: Egy magyar sz� egyik mag�nhangz�j�nak megad�sa
//Kiv�laszt�si t�tel alapj�n - magyar szavakban biztosan van legal�bb egy mag�nhagz�!!!
////indextartomany transzform�ci�ja az 1..N intervallumr�l a 0..N-1 tartomanyra
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
    const int mghDb=10;                     //mag�nhangz�k sz�ma
    const char mgh[10]={'a','e','o','u','i','A','E','O','U','I'};   //el�fordul� mag�nhangz�k - �kezetes bet�ket, most nem �br�zoljuk
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
