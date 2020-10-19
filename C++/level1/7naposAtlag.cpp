
//Feladat: Adjuk meg az egy hetes átlagokat egy hõmérséklet sorozatban
//A tömb indextartományát a 0-N-1 tartományra transzformáljuk
#include <iostream>

using namespace std;
    const int maxN=100;
    void beolvasas(int &N,int H[]);
    void atlagolas(const int N,const int H[],float A[]);
    void kiiras(const int N,const float A[]);
int main()
{   int N;
    int H[maxN];                // hõmérsékletet tartalmazó tömb
    float A[maxN];               // +,- -t taratlmazó eredménytömb
    cout<<"Elmult napok deli homersekletet ismerjuk, mikor volt pozitiv vagy negativ a mert ertek?"<<endl<<endl;
    beolvasas(N,H);
    atlagolas(N,H,A);
    kiiras(N-6,A);
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
void atlagolas(const int N,const int H[],float A[]){
    float S;
    S=0.0;
    for (int j=0;j<7;j++){
        S+=H[j];
    }
    A[0]=S/7;
    for (int i=7;i<N;++i){
        S=S-H[i-7]+H[i];
        A[i-6]=S/7;
    }

}
void kiiras(const int N,const float A[]){
    cout<<"A mert deli homersekletek hetenkenti atlaga..."<<endl;
    if (N<0){
        cout<<"Nem volt teljes het.";
    }
    for (int i=0;i<N;++i){
        cout<<i<<". naptol kezdodo het atlaga "<<A[i]<<endl;
    }
}
