//Feladat: Beilleszt�ses rendez�s
//a p�ld�ban eg�sz sz�mokat tartalmaz� t�mbre

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
    int X[maxN]; //most val�s sz�mokat tartalmaz a t�mb
    cout << "Beilleszteses rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    BeillRendezes(N,X);
    kiiras("A rendezett sorozat: ",N,X); //eredm�ny ki�r�sa
    return 0;
}
void feltoltes( int &N,int X[]){
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    for (int i=0;i<N;++i){
        X[i]=rand()%1000; //0..999 k�z�tti sz�m
    };
}
void BeillRendezes(const int N,int X[]){
   //indextartom�ny 0..N-1 �s nem 1..N
    int s,j;

    for (int i=1;i<N;++i){
        j=i-1;
        while ((j>0)&&(X[j]>X[j+1])){
            s=X[j];X[j]=X[j+1];X[j+1]=s; //csere
            --j;
        }
        //kiiras("kovetkezo menet",N,X);
        //ha megjegyz�b�l kiveszi a megel�z� sort,
        //akkor egy-egy menet eredm�ny�t is ki�ratjuk
    }
};
void kiiras(const string szoveg,const int N,const int X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl<<endl;
};
