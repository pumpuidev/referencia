
//Feladat: Másolás-függvényszámítás
#include <iostream>

using namespace std;

void beolvasas(const int N,float X[]);
void fuggv(const int N,const float X[],const float Z[],float Y[]);
void kiiras(const int N,const float X[],const float Z[],float Y[]);
int main()
{
    int N;
    cout << "Masolas -fuggvenyszamitas" << endl<<endl;
    do {
        cout<<"Hany elemu tombot hasznalunk?";
        cin>>N;
    }while (N<=0);
    float X[N],Z[N],Y[N]; //dinamikusan meretezett tömb;


    beolvasas(N,X); //bemeneti tömbök
    beolvasas(N,Z);
    fuggv(N,X,Z,Y);
    kiiras(N,X,Z,Y); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". elemet:";
            cin>>X[i];
    };
}
void fuggv(const int N,const float X[],const float Z[],float Y[]){
    for (int i=0;i<N;++i){
        Y[i]=X[i]+Z[i];
    };
};
void kiiras(const int N,const float X[],const float Z[],float Y[]){
    cout<<"Az elso sorozat:"<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl;
    cout<<"A masodik sorozat:"<<endl;
    for (int i1=0;i1<N;++i1){
        cout<<Z[i1]<<", ";
    };
    cout<<endl;
    cout<<"A ket sorozat osszege "<<endl;
    for (int i2=0;i2<N;++i2){
        cout<<Y[i2]<<", ";
    };
    cout<<endl;

};
