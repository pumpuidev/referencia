
//Feladat: Egy folyószakasz vízmagasságot mérnek.
//Adjuk meg az árvizes szakaszokat 800>i. mérés és 800<i+1 mérés

#include <iostream>

using namespace std;

const int maxN=100;
void beolvasas(int &N,int F[]);
void arviziSzakasz(const int N,const int F[],int &Db);
void kiiras(const int N,const int F[],const int Db);

int main()
{   int N;
    int F[maxN];                // folyó vízmagasságai
    int Db;                     // árvizi szakaszok darabszáma
    cout<<"Arvizi szakaszok darabszama."<<endl<<endl;
    beolvasas(N,F);
    arviziSzakasz(N,F,Db);
    kiiras(N,F,Db);
    return 0;
}
void beolvasas(int &N,int F[]){
    do{
        cout<<"Hany szakaszon mertunk? (0.."<<maxN<<")";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //meresek szama csak nem negativ lehet
    for (int i=0;i<N;++i){
        cout<<i<<". szakasz magassaga (cm)";
        cin>>F[i];
    }
}
void arviziSzakasz(const int N,const int F[],int &Db){
    Db=0;
    for (int i=0;i<N-1;++i){
        if ((F[i]<=800)&&(F[i+1]>800)){
            Db=Db+1;
        }
    }
}
void kiiras(const int N,const int F[],const int Db){
    cout<<"A mert magassagok..."<<endl;
    for (int i=0;i<N;++i){
        cout<<F[i]<<", ";
    }
    cout<<" Az arvizi szakaszok szama: "<<Db<<endl;
}
