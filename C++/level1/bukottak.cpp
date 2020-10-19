
//Feladat: Van-e az oszt�lynak bukott tanul�ja
#include <iostream>

using namespace std;
const int maxN=100;
void beolvasas(int &N,int Jegy[]);
void vanBukott(const int N,const int Jegy[],bool &Bukotte);
void kiiras(const int N,const int Bukott[],bool Bukotte);

int main()
{   int N;
    bool Bukott ;                   //Bukott tanul� van-e
    int Jegy[maxN];                    // jegyek
    cout<<"Van-e bukott tanulo?"<<endl<<endl;
    beolvasas(N,Jegy);
    vanBukott(N,Jegy,Bukott);             //bool f�ggv�nyt is �rhatn�nk
    kiiras(N,Jegy,Bukott);
    return 0;
}
void beolvasas(int &N,int Jegy[]){
    do{
        cout<<"Mekkora az osztaly letszama (0.."<<maxN<<")?";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //gyerekek szama csak nem negativ lehet
    for (int i=0;i<N;++i){
        do{
            cout<<"Mennyi az osztaly "<<i<<". gyerekenek az osztalyzata(1..5)?"; //a jegyek 1-5 k�z�ttiek
            cin>>Jegy[i];
        }while(!((Jegy[i]<=5)&&(Jegy[i]>=1)));
    }
}
void vanBukott(const int N,const int Jegy[],bool &Bukotte){
    int i=0;
    while ((i<N)&&(Jegy[i]!=1)){
        ++i;       //az index transzform�lt a 0..N-1 intervalllumra
    };

    Bukotte=(i<N);

}
void kiiras(const int N,const int Jegy[],bool Bukotte){
    cout<<"Az "<<N<<" fos osztaly jegyei:"<<endl;
    for (int i=0;i<N;++i){
        cout<<Jegy[i]<<", ";
    }
    cout<<endl;
    if (Bukotte){
        cout<<"Van bukott tanulo!"<<endl;
    }
    else {
        cout<<"Nincs bukott tanulo!"<<endl;
    }
}
