
//Feladat: Döntsük el, hogy van-e legalább K darab 10000 Ft-nál nagyobb bevétele
//Tétel:   Megszámolás és eldöntés
//Kapcsolat tétellel: T tulajdonság 10000-nél nagyobb bevétel


#include <iostream>
#include <math.h>
using namespace std;
void beolvasas(const int N,float PenzForg[],int& K);
bool van_annyi(const int N,const float PenzForg[],const int K);
bool tizezernelTobb(float egy_bevetel);
void kiiras(const int N,const float PenzForg[],const int K, const bool van);
int main()
{
    int N,K;
    bool Van;
    cout << "Van-e legalabb K 10000Ft-nal nagyobb bevetel" << endl<<endl;
    do {
        cout<<"Hany adatunk van?";
        cin>>N;
    }while (N<=0);
    float PenzForg[N];
    int Max[N]; //dinamikusan meretezett tömb;
    beolvasas(N,PenzForg,K);
    Van=van_annyi(N,PenzForg,K);
    kiiras(N,PenzForg,K,Van); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float PenzForg[],int & K){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
    do{
        cout<<"Hany 10000 Ft-nal nagyobb bevetelrol van szo? (nagyobb 0)";
        cin>>K;
    }while(K<=0);
}
bool van_annyi(const int N,const float PenzForg[],const int K){
    int Db=0; //indextartomány 0..N-1 és nem 1..N
    int i=0;
    while ((i<N)&&(Db<K)){
        if (tizezernelTobb(PenzForg[i])){
            Db=Db+1;
        }
        i=i+1;
    }
    bool Van=(Db==K);
    return Van;
};
bool tizezernelTobb(float egy_bevetel){
    return 10000<egy_bevetel;
}
void kiiras(const int N,const float PenzForg[],const int K, const bool Van){
    cout<<"A penzforgalmunk:"<<endl;
    for (int i1=0;i1<N;++i1){
        cout<<PenzForg[i1]<<",";
    };
    cout<<endl;
    if (Van){
        cout<<"Van "<<K<<" darab 10000Ft-nal nagyobb atutalasunk "<<endl;
    }else{
           cout<<"Nincs "<<K<<" darab 10000-nel nagyobb bevetelunk"<<endl;
    }
};
