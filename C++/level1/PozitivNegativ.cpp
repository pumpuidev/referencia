
//Feladat: Adott egy hõmérséklet sorozat, állípítsuk meg, hogy melyek a pozitív és negatív napok
//A tömb indextartományát a 0-N-1 tartományra transzformáljuk
#include <iostream>

using namespace std;
    const int maxN=100;
    void beolvasas(int &N,int H[]);
    void feldolgozas(const int N,const int H[],char E[]);
    void kiiras(const int N,const int H[],const char E[]);
int main()
{
    int N;
    int H[maxN];                // hõmérsékletet tartalmazó tömb
    char E[maxN];               // +,- -t taratlmazó eredménytömb
    cout<<"Elmult napok deli homersekletet ismerjuk, mikor volt pozitiv vagy negativ a mert ertek?"<<endl<<endl;
    beolvasas(N,H);
    feldolgozas(N,H,E);
    kiiras(N,H,E);

    return 0;
}
void beolvasas(int &N,int H[]){
    do{
        cout<<"Hany napig mertunk? (1.."<<maxN<<")";
        cin>>N;
    }while (!((N>=0)&&(N<=maxN)));  //meresek szama csak nem negativ lehet
    for (int i=0;i<N;++i){
        cout<<i<<". nap homerseklete (Celsius)";
        cin>>H[i];
    }

}
void feldolgozas(const int N,const int H[],char E[]){
    for (int i=0;i<N;++i){
        if (H[i]>=0){
            E[i]='+';
        }
        else {
            E[i]='-';
        }
    }
}
void kiiras(const int N,const int H[],const char E[]){
    cout<<"A mert deli homersekletek es a pozitiv ill. negativ tartomanyba sorolasuk..."<<endl;
    for (int i=0;i<N;++i){
        cout<<i<<". napon "<<H[i]<<" Celsius fokot mertek, ez "<<E[i]<<endl;
    }
}
