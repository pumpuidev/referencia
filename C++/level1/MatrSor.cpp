
//Feladat: Egy uzletember N szamlaval rendelkezik, amelyeken keresztul zajlik a p�nzforgalom,
//M �tutal�s t�rt�nik egy-egy sz�ml�n. Adjuk meg, hogy mennyi a sz�mla �sszes�t�s ut�n a p�nze?
//T�tel: Sorozatsz�m�t�s

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
    kiiras(N,M,PenzForg,Ossz); //eredm�ny ki�r�sa
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
            cout<<"Kerem az "<<j<<". adatot (pozit�v - bevetel, negativ - kiadas):";
            cin>>PenzForg[i][j];
        }
    }
}
float osszesen(const int N,const int M,const float PenzForg[maxN][maxM]){
    float Ossz=0; // ebben �sszegezz�k az adatokat
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
