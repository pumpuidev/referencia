
//Feladat: Adott egy ember bevételeinek és kiadásainak éves mértéke. Mennyivel változott a vagyona év végére?
#include <iostream>

using namespace std;

const int maxN=100;
void beolvasas(int &N,int Be[],int Ki[]);
void mennyi(const int N,const int Be[],const int Ki[],int &S);
void kiiras(const int N,const int Be[],const int Ki[], const int S );

int main()
{   int N,S;                     //N bevetel es kiadas, S vagyon változása
    int Be[maxN],Ki[maxN];                // bevetelek es kiadasok
    cout<<"Bevetelek es kiadasok"<<endl<<endl;
    beolvasas(N,Be,Ki);
    mennyi(N,Be,Ki,S);
    kiiras(N,Be,Ki,S);
    return 0;
}
void beolvasas(int &N,int Be[],int Ki[]){
    do{
        cout<<"Hany bevetelunk ill kiadasunk volt? (0.."<<maxN<<")";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //napok szama csak nem negativ lehet
    for (int i=0;i<N;++i){
       do{
        cout<<i<<". bevetel: (>=0) "; //bevétel csak nem negatív lehet, különben a kiadások között kell tárolni
        cin>>Be[i];
       }while(Be[i]<0);
       do{
        cout<<i<<". kiadas: (>=0)";  //kiadás csak pozitív lehet, különben bevételnek számítana ;)))
        cin>>Ki[i];
       }while(Ki[i]<0);
    }
}
void mennyi(const int N,const int Be[],const int Ki[],int &S){
    //sorozatszámítási tétel alkalmazása
    S=0;
    for (int i=0;i<N;++i){
        S=S+Be[i]-Ki[i];
    }
}
void kiiras(const int N,const int Be[],const int Ki[], const int S ){
    cout<<"beveteleink es kiadasaink:"<<endl;

    for (int i=0;i<N;++i){
        cout<<Be[i]<<" bevetel,  "<<Ki[i]<<" kiadas"<<endl;
    }
    cout<<"Ev vegere a vagyona "<<S<<"FT-tal valtozott ";
}

