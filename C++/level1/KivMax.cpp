
//Feladat: Adjuk meg a legkisebb �rt�k� kiad�st, ha adott a teljes p�nzforgalom
//T�tel:   Kivalogat�s �s maxkiv�laszt�s
//Kapcsolat a t�tellel:T tulajdons�g� egy p�nzforgalmi adat, ha az negat�v, azaz kiad�s

#include <iostream>

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min);
bool Kiadas(float egybev_kiad); //T tulajdons�g megfelel�je
void kiiras(const int N,const float PenzForg[],const bool van,const int Min);
int main()
{
    int N,Db,Min;
    bool van;
    float OsszesBevetel;
    cout << "Legkisebb kiadasunk meghatarozasa" << endl<<endl;
    do {
        cout<<"Hany adatunk van?";
        cin>>N;
    }while (N<=0);
    float PenzForg[N]; //dinamikusan meretezett t�mb;

    beolvasas(N,PenzForg);

    legkisebbkiadas(N,PenzForg,van,Min);
    kiiras(N,PenzForg,van,Min); //eredm�ny ki�r�sa
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozit�v - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min){ //f�ggv�nyk�nt is megoldhattuk volna
    int Kiadasok[N];
    int Db=0;
    for (int i1=0;i1<N;++i1){
        if (Kiadas(PenzForg[i1])){
            Kiadasok[Db]=i1;    //a kiad�sok indexeit t�roljuk
            ++Db ; //indextartom�ny 0-t�l kezd�dik
        }
    }
    van=(Db>0);
    if (van){
        Min=0;
        for (int i2=0;i2<Db;++i2){
            if (PenzForg[Kiadasok[i2]]>PenzForg[Kiadasok[Min]]){  //a legnagyobb negat�v �rt�k a legkisebb kiad�s!!
                Min=Kiadasok[i2];
            }
        }
    }
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
