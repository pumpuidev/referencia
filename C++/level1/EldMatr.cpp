
//Feladat: Egy uzletember N szamlaval rendelkezik, amelyeken keresztul zajlik a pénzforgalom,
//M átutalás történik egy-egy számlán. Van-e 10000-nél nagyobb átutalasa
//Tétel: Sorozatszámítás

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=10;
const int maxM=10;
void beolvasas(int &N,int &M,float PenzForg[maxN][maxM]);
bool van_e(const int N,const int M,const float PenzForg[maxN][maxM]);
bool tizezernelTobb(float egy_bevetel);
void kiiras(const int N,const int M,const float PenzForg[maxN][maxM],const bool Van);
int main()
{
    int N,M;
    bool Van;
    float PenzForg[maxN][maxM];
    beolvasas(N,M,PenzForg);
    Van=van_e(N,M,PenzForg);
    kiiras(N,M,PenzForg,Van); //eredmény kiírása
    return 0;
}
void beolvasas(int &N,int &M,float PenzForg[maxN][maxM]){
    cout << "Atutalasok osszege tobb szamlan " << endl<<endl;
    do {
        cout<<"Hany szamlank van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>maxN));
    do {
        cout<<"Hany atutalas volt szamlankent? (1.."<<maxM<<")";
        cin>>M;
    }while ((M<=0)||(M>maxM));
    for (int i=0;i<N;++i){
        cout<<"Az "<<i<<". szamla atutalasai:"<<endl;
        for (int j=0;j<M;++j){
            cout<<"Kerem az "<<j<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i][j];
        }
    }
}
bool van_e(const int N,const int M,const float PenzForg[maxN][maxM]){
    int i=0,j=0;
    while ((i<N)&&!tizezernelTobb(PenzForg[i][j])){
       if (j<M-1){
           j=j+1;
       }
       else{
           j=0;
           i=i+1;
       }
    }
    return (i<N);
};
bool tizezernelTobb(float egy_bevetel){
    return 10000<egy_bevetel;
}
void kiiras(const int N,const int M,const float PenzForg[maxN][maxM], const bool Van){
    cout<<"A penzforgalmunk a szamlainkon:"<<endl;
    for (int i=0;i<N;++i){
      cout<<"Az "<<i<<". szamlank:"<<endl;
      for (int j=0;j<M;++j){
        cout<<PenzForg[i][j]<<",";
        };
        cout<<endl;
    };
    if (Van){
        cout<<"Van 10000-nel nagyobb atutalasunk"<<endl;
    }
    else{
         cout<<"Nincs egyik szamlan sem 10000-nel nagyobb atutalasunk"<<endl;
    }
};
