
//Feladat: Adjuk meg a legnagyobb �rt�k� �tutal�sokat, ha adott a teljes p�nzforgalom
//T�tel:   Maxkiv�laszt�s �s kiv�logat�s


#include <iostream>
#include <math.h>
using namespace std;
void beolvasas(const int N,float PenzForg[]);
void legnagyobbAtutalasok(const int N,const float PenzForg[],int &Db,int Max[]);
void kiiras(const int N,const float PenzForg[],const int Db,const int Max[]);
int main()
{
    int N,Db;
    cout << "A legnagyobb erteku atutalasok" << endl<<endl;
    do {
        cout<<"Hany adatunk van?";
        cin>>N;
    }while (N<=0);
    float PenzForg[N];
    int Max[N]; //dinamikusan meretezett t�mb;
    beolvasas(N,PenzForg);
    legnagyobbAtutalasok(N,PenzForg,Db,Max);
    kiiras(N,PenzForg,Db,Max); //eredm�ny ki�r�sa
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozit�v - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void legnagyobbAtutalasok(const int N,const float PenzForg[],int &Db,int Max[]){
    Db=1; //indextartom�ny 0..N-1 �s nem 1..N
    float MaxErt=fabs(PenzForg[0]);
    Max[0]=0;
    for (int i1=1;i1<N;++i1){
        if (fabs(PenzForg[i1])==MaxErt){
            Db=Db+1;
            Max[Db-1]=i1;
        }else{
            if (fabs(PenzForg[i1])>MaxErt){
                MaxErt=fabs(PenzForg[i1]);
                Db=1;
                Max[Db-1]=i1;
            }
        }
    }
};
void kiiras(const int N,const float PenzForg[],const int Db, const int Max[]){
    cout<<"A penzforgalmunk:"<<endl;
    for (int i1=0;i1<N;++i1){
        cout<<PenzForg[i1]<<",";
    };
    cout<<endl;
    cout<<"A kovetkezo sorszamu atutalasok voltak maximalisak:";
    for (int i2=0;i2<Db;++i2){
        cout<<Max[i2]<<",";
    };

};
