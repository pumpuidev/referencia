
//Feladat: Adjuk meg a legkisebb �rt�k� kiad�st, ha adott a teljes p�nzforgalom
//T�tel:   Kivalogat�s �s maxkiv�laszt�s
//Kapcsolat a t�tellel:T tulajdons�g� egy p�nzforgalmi adat, ha az negat�v, azaz kiad�s

#include <iostream>
#include <float.h> //legkisebb vagy legnagyobb val�s �rt�kek

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min);
bool Kiadas(float egybev_kiad); //T tulajdons�g megfelel�je
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
    N=N+1; //a fikt�v elemnek lefoglalunk egy plusz helyet
    float PenzForg[N]; //dinamikusan meretezett t�mb;

    beolvasas(N,PenzForg);

    legkisebbkiadas(N,PenzForg,van,Min);
    kiiras(N,PenzForg,van,Min); //eredm�ny ki�r�sa
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    PenzForg[0]=-FLT_MAX ;//0. elem legyen a legkisebb �br�zolhat� val�s sz�m
    for (int i=1;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozit�v - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min){ //f�ggv�nyk�nt is megoldhattuk volna
     // PenzForg[0]=-FLT_MAX ;0. elem a legkisebb eg�sz sz�m
    Min=0;
    for (int i1=1;i1<N;++i1){
        cout<<PenzForg[0]<<"."<<Min<<endl;
        if ((Kiadas(PenzForg[i1]))&&(PenzForg[Min]<PenzForg[i1])){
            Min=i1;    //a kiad�sok indexeit t�roljuk
        }
    }
    van=(Min>0);
};
bool Kiadas(float egybev_kiad){
    return egybev_kiad<0; //kiadas, ha nagyobb 0-n�l
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

