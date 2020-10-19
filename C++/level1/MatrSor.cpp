
//Feladat: Egy uzletember N szamlaval rendelkezik, amelyeken keresztul zajlik a pénzforgalom,
//M átutalás történik egy-egy számlán. Adjuk meg, hogy mennyi a számla összesítés után a pénze?
//Tétel: Sorozatszámítás

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=10;
const int maxM=10;
void beolvasas(int &N,int &M,float PenzForg[maxN][maxM]);
float osszesen(const int N,const int M,const float PenzForg[maxN][maxM]);
void kiiras(const int N,const int M,const float PenzForg[maxN][maxM],const float Ossz);
int main()
{
    int N,M;
    float Ossz;
    float PenzForg[maxN][maxM];
    beolvasas(N,M,PenzForg);
    Ossz=osszesen(N,M,PenzForg);
    kiiras(N,M,PenzForg,Ossz); //eredmény kiírása
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
float osszesen(const int N,const int M,const float PenzForg[maxN][maxM]){
    float Ossz=0; // ebben összegezzük az adatokat
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            Ossz+=PenzForg[i][j];
        }
    }
    return Ossz;
};
void kiiras(const int N,const int M,const float PenzForg[maxN][maxM], const float Ossz){
    cout<<"A penzforgalmunk a szamlainkon:"<<endl;
    for (int i=0;i<N;++i){
        cout<<"Az "<<i<<". szamlank:"<<endl;
        for (int j=0;j<M;++j){
            cout<<PenzForg[i][j]<<",";
        };
        cout<<endl;
    };
    cout<<"A szamlak osszesitese:"<<Ossz<<endl;
};
