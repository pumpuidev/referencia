//Feladat: Beillesztéses rendezés
//a példában egész számokat tartalmazó tömbre

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=100;
void feltoltes( int &N,int X[]);
void BeillRendezes(const int N,int X[]);
void kiiras(const string szoveg,const int N,const int X[]);
int main()
{
    int N;
    int X[maxN]; //most valós számokat tartalmaz a tömb
    cout << "Beilleszteses rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    BeillRendezes(N,X);
    kiiras("A rendezett sorozat: ",N,X); //eredmény kiírása
    return 0;
}
void feltoltes( int &N,int X[]){
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    for (int i=0;i<N;++i){
        X[i]=rand()%1000; //0..999 közötti szám
    };
}
void BeillRendezes(const int N,int X[]){
   //indextartomány 0..N-1 és nem 1..N
    int s,j;

    for (int i=1;i<N;++i){
        j=i-1;
        while ((j>0)&&(X[j]>X[j+1])){
            s=X[j];X[j]=X[j+1];X[j+1]=s; //csere
            --j;
        }
        //kiiras("kovetkezo menet",N,X);
        //ha megjegyzébõl kiveszi a megelõzõ sort,
        //akkor egy-egy menet eredményét is kiíratjuk
    }
};
void kiiras(const string szoveg,const int N,const int X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl<<endl;
};
