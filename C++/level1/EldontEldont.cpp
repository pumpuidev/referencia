
//Feladat: Döntsük el, hogy két számlán volt-e azonos értékû átutalás
//Tétel:   eldöntés és eldöntés



#include <iostream>
#include <math.h>
using namespace std;
void beolvasas(const int N,float PenzForg[]);
bool van_azonos(const int N,const float PenzForg[],const int M,const float PenzForg2[]);
void kiiras(const int N,const float PenzForg[],const int M,const float PenzForg2[],const bool van);
int main()
{
    int N,M;
    bool Van;
    cout << "Van-e azonos atutalas ket szamlan " << endl<<endl;
    do {
        cout<<"Hany adatunk van az elso szamlan?";
        cin>>N;
    }while (N<=0);
    float PenzForg[N];
    beolvasas(N,PenzForg);
    do {
        cout<<"Hany adatunk van a masodik szamlan?";
        cin>>M;
    }while (M<=0);
    float PenzForg2[M];
    beolvasas(M,PenzForg2);
    Van=van_azonos(N,PenzForg,M,PenzForg2);
    kiiras(N,PenzForg,M,PenzForg2,Van); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
bool van_azonos(const int N,const float PenzForg[],const int M,const float PenzForg2[]){
    int i=0,j;
    bool Van=false;
    while ((i<N)&&!Van){
        j=0;
        while ((j<M)&&(PenzForg[i]!=PenzForg2[j])){
            j=j+1;
        }
        if (j<M){
            Van=true;
        }else{
            i=i+1;
        }
    }
    return Van;
};
void kiiras(const int N,const float PenzForg[],const int M,const float PenzForg2[], const bool Van){
    cout<<"A penzforgalmunk az egyik szamlan:"<<endl;
    for (int i1=0;i1<N;++i1){
        cout<<PenzForg[i1]<<",";
    };
    cout<<endl;
     cout<<"A penzforgalmunk a masik szamlan:"<<endl;
    for (int i2=0;i2<M;++i2){
        cout<<PenzForg2[i2]<<",";
    };
    cout<<endl;
    if (Van){
        cout<<"Van kozos erteku atutalas a ket szamlan"<<endl;
    }else{
           cout<<"Nincs egyforma atutalasi osszeg a ket szamlan"<<endl;
    }
};
