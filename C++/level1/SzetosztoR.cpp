//Feladat: Szétosztó rendezés
//a példában rekordokat tartalmazó tömbre

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=100;
struct Rekord{
    int kulcs;
    int adat;
};
void feltoltes( int &N,Rekord X[]);
void SzetosztoRendezes(const int N,const Rekord X[],Rekord Y[]);
void kiiras(const string szoveg,const int N,const Rekord X[]);
int main()
{
    int N;
    Rekord X[maxN],Y[maxN]; //most rekordokat  tartalmaz a tömb
    cout << "Szétosztó rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    SzetosztoRendezes(N,X,Y);
    kiiras("A rendezett sorozat: ",N,Y); //eredmény kiírása
    return 0;
}
void feltoltes( int &N,Rekord X[]){
    int egyik,masik;
    Rekord cs;
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    for (int i=0;i<N;++i){
        X[i].kulcs=i; //0..N közötti számokkal feltöltjük a tömb kulcs mezõjét
        X[i].adat=rand()%1000; //az adat egy 0..999 közötti szám
    };
    for (int j=1;j<100;++j){
        egyik=rand()%N ;//0..99 közötti véletlenszám
        masik=rand()%N ;
        cs=X[egyik];X[egyik]=X[masik];X[masik]=cs; //megcserélek két véletlenszerûen
                                                    //kiválasztott értéket - megkeverem
                                                    //ezzel biztosítom a permutációt
    }
}
void SzetosztoRendezes(const int N, const Rekord X[],Rekord Y[]){
   //indextartomány 0..N-1 és nem 1..N
    for (int i=0;i<N;++i){
        Y[X[i].kulcs]=X[i];
        }
};
void kiiras(const string szoveg,const int N,const Rekord X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i].kulcs<<":"<<X[i].adat<<endl;
    };
    cout<<endl<<endl;
};
