//Feladat: Számlálva szétosztó rendezés
//a példában egészeket tartalmazó tömbre

#include <iostream>
#include <math.h>
using namespace std;
const int maxN=100;
void feltoltes( int &N,int X[],int& M);
void SzamlSzetosztoRendezes(const int N,const int M,const int X[],int Y[]);
void kiiras(const string szoveg,const int N,const int X[]);
int main()
{
    int N,M;
    int X[maxN],Y[maxN]; //most rekordokat  tartalmaz a tömb
    cout << "Szamlalva szetoszto rendezes" << endl<<endl;
    feltoltes(N,X,M);
    kiiras("Az eredeti sorozat: ",N,X);
    SzamlSzetosztoRendezes(N,M,X,Y);
    kiiras("A rendezett sorozat: ",N,Y); //eredmény kiírása
    return 0;
}
void feltoltes( int &N,int X[],int& M){
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    do{
        cout<<"Milyen intervallumba tartoznak az adatok? (0.."<<maxN<<")";
        cin>>M;
    }while((M<=0)||(M>=maxN));

    for (int i=0;i<N;++i){
        X[i]=rand()%M; //0..M-1 közötti számokkal feltöltjük a tömböt
    };
}
void SzamlSzetosztoRendezes(const int N,const int M, const int X[],int Y[]){
   //indextartomány 0..N-1 és nem 1..N
    int Db[N],i;
    for (i=0;i<N;++i){
        Db[i]=0;
    }
    for (i=0;i<N;++i){
        ++Db[X[i]]; //Db[X[i]]=Db[X[i]]+1;
        }           //pl Db[3]-ban az az érték van, hogy hol van az eredményben
                    //az utolsó 3-as érték.

    for (i=1;i<M;++i){
        Db[i]=Db[i]+Db[i-1];
    }
    for (i=0;i<N;++i){
        Y[Db[X[i]]-1]=X[i]; //index tartomány!!
        --Db[X[i]];
    }
};
void kiiras(const string szoveg,const int N,const int X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<","<<endl;
    };
    cout<<endl<<endl;
};
