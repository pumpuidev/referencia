
//Feladat: Adjuk meg a legkisebb értékû kiadást, ha adott a teljes pénzforgalom
//Tétel:   Kivalogatás és maxkiválasztás
//Kapcsolat a tétellel:T tulajdonságú egy pénzforgalmi adat, ha az negatív, azaz kiadás

#include <iostream>

using namespace std;
void beolvasas(const int N,float PenzForg[]);
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min);
bool Kiadas(float egybev_kiad); //T tulajdonság megfelelõje
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
    float PenzForg[N]; //dinamikusan meretezett tömb;

    beolvasas(N,PenzForg);

    legkisebbkiadas(N,PenzForg,van,Min);
    kiiras(N,PenzForg,van,Min); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,float PenzForg[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". adatot (pozitív - bevetel, negativ - kiadas):";
            cin>>PenzForg[i];
    };
}
void legkisebbkiadas(const int N,const float PenzForg[],bool & van,int & Min){ //függvényként is megoldhattuk volna
    int Kiadasok[N];
    int Db=0;
    for (int i1=0;i1<N;++i1){
        if (Kiadas(PenzForg[i1])){
            Kiadasok[Db]=i1;    //a kiadások indexeit tároljuk
            ++Db ; //indextartomány 0-tól kezdõdik
        }
    }
    van=(Db>0);
    if (van){
        Min=0;
        for (int i2=0;i2<Db;++i2){
            if (PenzForg[Kiadasok[i2]]>PenzForg[Kiadasok[Min]]){  //a legnagyobb negatív érték a legkisebb kiadás!!
                Min=Kiadasok[i2];
            }
        }
    }
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
