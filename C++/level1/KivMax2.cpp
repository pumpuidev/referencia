
//Feladat: Adjuk meg a legkisebb értékû kiadást, ha adott a teljes pénzforgalom
//Tétel:   Kivalogatás és maxkiválasztás
//Kapcsolat a tétellel:T tulajdonságú egy pénzforgalmi adat, ha az negatív, azaz kiadás

#include <iostream>
#include <float.h> //legkisebb vagy legnagyobb valós értékek

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min);
bool Kiadas(float egybev_kiad); //T tulajdonság megfelelõje
void kiiras(const int N,const float PenzForg[],const bool van,const int Min);
int main()
{
    int N,Min;
    bool van;
    cout << "Legkisebb kiadasunk meghatarozasa" << endl<<endl;
    do {
        cout<<"Hany adatunk van?";
        cin>>N;
    }while (N<=0);
    N=N+1; //a fiktív elemnek lefoglalunk egy plusz helyet
    float PenzForg[N]; //dinamikusan meretezett tömb;

    beolvasas(N,PenzForg);

    legkisebbkiadas(N,PenzForg,van,Min);
    kiiras(N,PenzForg,van,Min); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    PenzForg[0]=-FLT_MAX ;//0. elem legyen a legkisebb ábrázolható valós szám
    for (int i=1;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min){ //függvényként is megoldhattuk volna
     // PenzForg[0]=-FLT_MAX ;0. elem a legkisebb egész szám
    Min=0;
    for (int i1=1;i1<N;++i1){
        cout<<PenzForg[0]<<"."<<Min<<endl;
        if ((Kiadas(PenzForg[i1]))&&(PenzForg[Min]<PenzForg[i1])){
            Min=i1;    //a kiadások indexeit tároljuk
        }
    }
    van=(Min>0);
};
bool Kiadas(float egybev_kiad){
    return egybev_kiad<0; //kiadas, ha nagyobb 0-nál
};
void kiiras(const int N,const float PenzForg[],const bool van, const int Min){
    cout<<"A penzforgalmunk:"<<endl;
    for (int i=0;i<N;++i){
        cout<<PenzForg[i]<<",";
    };
    cout<<endl;
    if (van){
        cout<<"A legkisebb erteku kiadasunk:"<<PenzForg[Min]<<" Ft volt"<<endl;
    }
    else{
        cout<<"Nem volt kiadasunk"<<endl;
    }
};

