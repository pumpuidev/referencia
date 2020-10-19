
//Feladat: Adjuk meg az �sszes bev�telt, ha adott a teljes p�nzforgalom
//T�tel: Kivalogat�s �s �sszegz�s (felt�teles �sszegz�s)
//Kapcsolat a t�tellel: T tulajdons�g� egy p�nzforgalmi adat, ha az pozit�v, azaz bev�tel

#include <iostream>

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void kivalogatas_osszegzes(const int N,const float PenzForg[],float & OsszesBevetel);
bool Bevetel(const float egybev_kiad); //T tulajdons�g
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
    float PenzForg[N]; //dinamikusan meretezett t�mb;

    beolvasas(N,PenzForg);

    kivalogatas_osszegzes(N,PenzForg,OsszesBevetel);
    kiiras(N,PenzForg,OsszesBevetel); //eredm�ny ki�r�sa
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozit�v - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void kivalogatas_osszegzes(const int N,const float PenzForg[],float & OsszesBevetel){ //f�ggv�nyk�nt is megoldhattuk volna
    float s=0;
    for (int i1=0;i1<N;++i1){
        if (Bevetel(PenzForg[i1])>0){
            s+=PenzForg[i1];
        }
    }
    OsszesBevetel=s;
};
bool Bevetel(float egybev_kiad){
    return egybev_kiad>0; //bev�tel, ha nagyobb 0-n�l
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
