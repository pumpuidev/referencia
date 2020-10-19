
//Feladat: Sz�mtani sorozat, K kezd��rt�k, L l�p�sk�z,elso N tag kisz�m�t�sa
#include <iostream>

using namespace std;

const int maxN=100;
void beolvasas(int &K,int &L,int &N);
void szamtani(const int K,const int L,const int N,int S[]);
void kiiras(const int K,const int L,const int N,const int S[]);

int main()
{   int K,L,N;                     //N napig j�rtunk l�versenyre, X p�nz�nk van kezdetben, Nap-on kell k�lcs�nk�rni
    int S[maxN];                // naponk�nt nyeres�gek, vagy vesztes�gek
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
    cout<<"Mennyi a sorozat elso tagja? "; //az el�felt�tel nem �rja el�, hogy csak pozit�v adatot haszn�lhatunk
    cin>>K;
    cout<<"Mennyi a sorozat lepeskoze? "; //az el�felt�tel nem �rja el�, hogy csak pozit�v adatot haszn�lhatunk
    cin>>L;

}
void szamtani(const int K,const int L,const int N,int S[]){
    for (int i=0;i<N;++i){
        S[i]=K+(i)*L;       //az index transzform�lt a 0..N-1 intervalllumra
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

