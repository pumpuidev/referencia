
//Feladat: L�versenyre j�runk N napon kereszt�l. X volt az indul� �sszeg.
//Naponk�nt nyer�nk vagy veszt�nk.Mikor kell el�sz�r k�lcs�nk�rni?

#include <iostream>

using namespace std;

const int maxN=100;
void beolvasas(int &N,int P[],int &X);
void kolcsonkeres(const int N,const int P[],const int X,bool &Van,int &Nap);
void kiiras(const int N,const int P[],const int X,const bool Van, const int Nap );

int main()
{   int N,X,Nap;                     //N napig j�rtunk l�versenyre, X p�nz�nk van kezdetben, Nap-on kell k�lcs�nk�rni
    int P[maxN];                // naponk�nt nyeres�gek, vagy vesztes�gek
    bool Van;                   //Van olyan nap, amikor k�lcs�n kell k�rni
    cout<<"Loversenyezes.Mikor kell eloszor kolcsonkerni?"<<endl<<endl;
    beolvasas(N,P,X);
    kolcsonkeres(N,P,X,Van,Nap);
    kiiras(N,P,X,Van,Nap);
    return 0;
}
void beolvasas(int &N,int P[],int &X){
    do{
        cout<<"Hany napig loversenyezunk? (0.."<<maxN<<")";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //napok szama csak nem negativ lehet
    cout<<"Mennyi volt az indulo osszeg? "; //az el�felt�tel nem �rja el�, hogy csak pozit�v adatot haszn�lhatunk
    cin>>X;

    for (int i=0;i<N;++i){
        cout<<i<<". napi nyereseg vagy veszteseg osszege FT-ban ";
        cin>>P[i];
    }
}
void kolcsonkeres(const int N,const int P[],const int X,bool &Van,int &Nap){
    int S=0;
    int i=0;
    while ((i<N)&&((S+P[i])>=0)){
        S+=P[i];
        ++i;
    }
    Van=(i<N);
    if (Van){
        Nap=i;
    }

}
void kiiras(const int N,const int P[],const int X,const bool Van, const int Nap ){
    cout<<X<<" FT-unk volt kezdetben."<<endl;
    cout<<"A verseny napjainak nyeresege es vesztesege..."<<endl;
    for (int i=0;i<N;++i){
        cout<<P[i]<<", ";
    }
    if (Van){
        cout<<endl<<" Az elso nap, amikor kolcson kellett kerni a(z) " <<Nap<<"."<<endl;
    }
    else {
       cout<<endl<<" Nem volt olyan nap, amikor kolcson kellett kerni..."<<endl;
    }

}

