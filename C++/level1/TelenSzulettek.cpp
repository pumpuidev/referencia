
//Feladat: Hanyan szulettek telen?
#include <iostream>

using namespace std;
const int maxN=100;
void beolvasas(int &N,int Szul[]);
void telenszulettek(const int N,const int Szul[],int &Db);
void kiiras(const int N,const int Szul[],const int Db);

int main()
{   int N,Db;      //hany ember szuletesi honapjat kerjuk be, hányan születtek téli hónapban
    int Szul[maxN];                    // szuletesi honapok
    cout<<"Hanyan szulettek telen? "<<endl<<endl;
    beolvasas(N,Szul);
    telenszulettek(N,Szul,Db);
    kiiras(N,Szul,Db);
    return 0;
}
void beolvasas(int &N,int Szul[]){
    do{
        cout<<"Hany ember szuletesi idejet taroljuk (0.."<<maxN<<")?";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //emberek szama csak nem negativ lehet
    for (int i=0;i<N;++i){
        do{
            cout<<"Melyik honapban szuletett a(z)"<<i<<". ember(1..12)?"; //a jegyek 1-5 közöttiek
            cin>>Szul[i];
        }while(!((Szul[i]<=12)&&(Szul[i]>=1)));
    }
}
void telenszulettek(const int N,const int Szul[], int &Db){
    Db=0;
    for (int i=0;i<N;++i){
        if ((Szul[i]<3)||(Szul[i]==12)){
                ++Db;
        }       //az index transzformált a 0..N-1 intervalllumra
    };
}
void kiiras(const int N,const int Szul[],const int Db){
    cout<<"Az "<<N<<" ember szuletesi honapja:"<<endl;
    for (int i=0;i<N;++i){
        cout<<Szul[i]<<", ";
    }
    cout<<endl;
    cout<<Db<<" ember szuletett telen"<<endl;
}
