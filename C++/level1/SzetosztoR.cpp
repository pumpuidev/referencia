//Feladat: Sz�toszt� rendez�s
//a p�ld�ban rekordokat tartalmaz� t�mbre

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
    Rekord X[maxN],Y[maxN]; //most rekordokat  tartalmaz a t�mb
    cout << "Sz�toszt� rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    SzetosztoRendezes(N,X,Y);
    kiiras("A rendezett sorozat: ",N,Y); //eredm�ny ki�r�sa
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
        X[i].kulcs=i; //0..N k�z�tti sz�mokkal felt�ltj�k a t�mb kulcs mez�j�t
        X[i].adat=rand()%1000; //az adat egy 0..999 k�z�tti sz�m
    };
    for (int j=1;j<100;++j){
        egyik=rand()%N ;//0..99 k�z�tti v�letlensz�m
        masik=rand()%N ;
        cs=X[egyik];X[egyik]=X[masik];X[masik]=cs; //megcser�lek k�t v�letlenszer�en
                                                    //kiv�lasztott �rt�ket - megkeverem
                                                    //ezzel biztos�tom a permut�ci�t
    }
}
void SzetosztoRendezes(const int N, const Rekord X[],Rekord Y[]){
   //indextartom�ny 0..N-1 �s nem 1..N
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
