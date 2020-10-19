
//Feladat: Számtani sorozat, K kezdõérték, L lépésköz,elso N tag kiszámítása
#include <iostream>

using namespace std;

const int maxN=100;
void beolvasas(int &K,int &L,int &N);
void szamtani(const int K,const int L,const int N,int S[]);
void kiiras(const int K,const int L,const int N,const int S[]);

int main()
{   int K,L,N;                     //N napig jártunk lóversenyre, X pénzünk van kezdetben, Nap-on kell kölcsönkérni
    int S[maxN];                // naponként nyereségek, vagy veszteségek
    cout<<"Szamtani sorozat."<<endl<<endl;
    beolvasas(K,L,N);
    szamtani(K,L,N,S);
    kiiras(K,L,N,S);
    return 0;
}
void beolvasas(int &K,int &L,int &N){
    do{
        cout<<"Hany tagot szamoljunk ki a sorozatbol? (0.."<<maxN<<")";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //napok szama csak nem negativ lehet
    cout<<"Mennyi a sorozat elso tagja? "; //az elõfeltétel nem írja elõ, hogy csak pozitív adatot használhatunk
    cin>>K;
    cout<<"Mennyi a sorozat lepeskoze? "; //az elõfeltétel nem írja elõ, hogy csak pozitív adatot használhatunk
    cin>>L;

}
void szamtani(const int K,const int L,const int N,int S[]){
    for (int i=0;i<N;++i){
        S[i]=K+(i)*L;       //az index transzformált a 0..N-1 intervalllumra
    }
}
void kiiras(const int K,const int L,const int N,const int S[]){
    cout<<"Szamtani sorozat"<<endl;
    cout<<K<<" az elso tag"<<endl;
    cout<<L<<" a lepeskoz"<<endl;
    cout<<"Az elso "<<N<<" tag:"<<endl;
    for (int i=0;i<N;++i){
        cout<<S[i]<<", ";
    }
}

