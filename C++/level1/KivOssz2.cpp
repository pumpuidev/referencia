
//Feladat: Adjuk meg az összes bevételt, ha adott a teljes pénzforgalom
//Tétel: Kivalogatás és összegzés (feltételes összegzés)
//Kapcsolat a tétellel: T tulajdonságú egy pénzforgalmi adat, ha az pozitív, azaz bevétel

#include <iostream>

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void kivalogatas_osszegzes(const int N,const float PenzForg[],float & OsszesBevetel);
bool Bevetel(const float egybev_kiad); //T tulajdonság
void kiiras(const int N,const float PenzForg[],const float OsszesBevetel);
int main()
{
    int N,Db;
    float OsszesBevetel;
    cout << "Osszes bevetel megadasa - kivalogatas es osszegzes tetel" << endl<<endl;
    do {
        cout<<"Hany adatunk van?";
        cin>>N;
    }while (N<=0);
    float PenzForg[N]; //dinamikusan meretezett tömb;

    beolvasas(N,PenzForg);

    kivalogatas_osszegzes(N,PenzForg,OsszesBevetel);
    kiiras(N,PenzForg,OsszesBevetel); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void kivalogatas_osszegzes(const int N,const float PenzForg[],float & OsszesBevetel){ //függvényként is megoldhattuk volna
    float s=0;
    for (int i1=0;i1<N;++i1){
        if (Bevetel(PenzForg[i1])>0){
            s+=PenzForg[i1];
        }
    }
    OsszesBevetel=s;
};
bool Bevetel(float egybev_kiad){
    return egybev_kiad>0; //bevétel, ha nagyobb 0-nál
};
void kiiras(const int N,const float PenzForg[],const float OsszesBevetel){
    cout<<"A penzforgalmunk:"<<endl;
    for (int i=0;i<N;++i){
        cout<<PenzForg[i]<<",";
    };
    cout<<endl;
    cout<<"Az osszes bevetelunk:"<<OsszesBevetel<<" Ft volt"<<endl;
    cout<<endl;
};
