
//Feladat: Egy ember telefonszámai és email címei között keresünk
#include <iostream>

using namespace std;

const int maxT=100; //maximum ennyi  telefonszám
const int maxE=100; //maximum ennyi email cím
struct Ember{
   int dbt,dbe;
   string telefon[maxT]; //telefonszámok
   string elevel[maxE];  //email címek
};
void beolvasas(Ember& X);
void be(string & Tel,string &Elev);
bool kereses(const Ember X,const string Tel,const string Elev);
void kiiras(const Ember X,const string Tel,const string Elev,bool &Lehet);
int main()
{
    Ember X;
    string Tel,Elev;
    bool Lehet;
    cout << "Adott ember elérhetõségei" << endl<<endl;
    beolvasas(X);
    be(Tel,Elev);
    Lehet=kereses(X,Tel,Elev);
    kiiras(X,Tel,Elev,Lehet);
    return 0;
}
void beolvasas(Ember & X){
    do {
        cout<<"Hany telefonszamot tarolunk (1.."<<maxT<<")";
        cin>>X.dbt;
    }while(!((X.dbt<maxT)&&(X.dbt>0)));
    for (int i=0;i<X.dbt;++i){
            cout<<"Kerem az "<<i<<". telefonszamot:";
            cin>>X.telefon[i];
    };
    do {
        cout<<"Hany email cimet tarolunk (1.."<<maxE<<")";
        cin>>X.dbe;
    }while(!((X.dbe<maxE)&&(X.dbe>0)));
    for (int i1=0;i1<X.dbe;++i1){
        cout<<"Kerem az "<<i1<<". email cimet:";
        cin>>X.elevel[i1];
    };

}
void be(string & Tel,string &Elev){
    cout<<"Adja meg a telefonszamot:";
    cin>>Tel;
    cout<<"Adja meg az elevel cimet:";
    cin>>Elev;
};
bool kereses(const Ember X,const string Tel,const string Elev){
    int i=0;
    int j;
    while ((i<X.dbt)&&(X.telefon[i].compare(Tel)!=0)){
        ++i;
    }
    if (i<X.dbt){
        j=0;
        while ((j<X.dbe)&&(X.elevel[j].compare(Elev)!=0)){
        ++j;
        }
    }
    return ((i<X.dbt)&&(j<X.dbe));
};
void kiiras(const Ember X,const string Tel,const string Elev,bool &Lehet){
    int O,P,M;
    cout<<"Az ember elerhetosegei:"<<endl;
    for (int i=0;i<X.dbt;++i){
        cout<<X.telefon[i]<<",";
    };
    cout<<endl;
    for (int i1=0;i1<X.dbe;++i1){
        cout<<X.elevel[i1]<<", ";
    };
    cout<<endl;
    cout<<"Telefon: "<<Tel<<" Elevel:"<<Elev<<endl;
    if (Lehet){
        cout<<"A telefonszam es az elevel cim is hozza tartozik.";
    }
    else{
        cout<<"Nem tartozik az illetohoz mindket elerhetoseg!";
    }
};
