
//Feladat: Kivalogatás - azok a napok, amikor nem fagyott délben

#include <iostream>

using namespace std;
void beolvasas(const int N,float X[]);
void kivalogatas(const int N,const float X[],int & Db,float Y[]);
void kiiras(const int N,const float X[],const int Db,const float Y[]);
int main()
{
    int N,Db;
    cout << "Kivalogatas - fagymentes napok" << endl<<endl;
    do {
        cout<<"Hany elemu tombot hasznalunk?";
        cin>>N;
    }while (N<=0);
    float X[N],Y[N]; //dinamikusan meretezett tömb;

    beolvasas(N,X); //bemeneti tömb - hõmérsékletek sorozata

    kivalogatas(N,X,Db,Y);
    kiiras(N,X,Db,Y); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". elemet:";
            cin>>X[i];
    };
}
void kivalogatas(const int N,const float X[],int & Db,float Y[]){
    Db=0;
    for (int i=0;i<N;++i){
        if (X[i]>0){
            Y[Db]=i;++Db;
        }
    };
};
void kiiras(const int N,const float X[],const int Db,const float Y[]){
    cout<<"A homersekletek:"<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl;
    cout<<Db<<" szamu fagymentes nap volt, amelyek sorszama:";
    for (int i1=0;i1<Db;++i1){
        cout<<Y[i1]<<", ";
    };
    cout<<endl;
};
