//Feladat: Sz�ml�l� rendez�s
//a p�ld�ban eg�szeket tartalmaz� t�mbre

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=100;
void feltoltes( int &N,int X[]);
void SzamlRendezes(const int N,const int X[],int Y[]);
void kiiras(const string szoveg,const int N,const int X[]);
int main()
{
    int N;
    int X[maxN],Y[maxN]; //most rekordokat  tartalmaz a t�mb
    cout << "Szamlalo rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    SzamlRendezes(N,X,Y);
    kiiras("A rendezett sorozat: ",N,Y); //eredm�ny ki�r�sa
    return 0;
}
void feltoltes( int &N,int X[]){
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    for (int i=0;i<N;++i){
        X[i]=rand()%1000; //0..999 k�z�tti sz�mokkal felt�ltj�k a t�mb�t
    };
}
void SzamlRendezes(const int N,const int X[],int Y[]){
   //indextartom�ny 0..N-1 �s nem 1..N
    int Db[N],i,j;
    for (i=0;i<N;++i){
        Db[i]=0;    //inicializ�l�s
    }
    for (i=0;i<N-1;++i){
     for (j=i+1;j<N;++j){
        if (X[i]>X[j]){
            ++Db[i];
        }else{
            ++Db[j];
        }
     }
    }
    for (i=0;i<N;++i){
        Y[Db[i]]=X[i]; //index tartom�ny!!
    }
};
void kiiras(const string szoveg,const int N,const int X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<","<<endl;
    };
    cout<<endl<<endl;
};

