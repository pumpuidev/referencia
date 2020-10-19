//Feladat: Számláló rendezés
//a példában egészeket tartalmazó tömbre

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
    int X[maxN],Y[maxN]; //most rekordokat  tartalmaz a tömb
    cout << "Szamlalo rendezes" << endl<<endl;
    feltoltes(N,X);
    kiiras("Az eredeti sorozat: ",N,X);
    SzamlRendezes(N,X,Y);
    kiiras("A rendezett sorozat: ",N,Y); //eredmény kiírása
    return 0;
}
void feltoltes( int &N,int X[]){
    do {
        cout<<"Hany adatunk van? (1.."<<maxN<<")";
        cin>>N;
    }while ((N<=0)||(N>=maxN));
    for (int i=0;i<N;++i){
        X[i]=rand()%1000; //0..999 közötti számokkal feltöltjük a tömböt
    };
}
void SzamlRendezes(const int N,const int X[],int Y[]){
   //indextartomány 0..N-1 és nem 1..N
    int Db[N],i,j;
    for (i=0;i<N;++i){
        Db[i]=0;    //inicializálás
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
        Y[Db[i]]=X[i]; //index tartomány!!
    }
};
void kiiras(const string szoveg,const int N,const int X[]){
    cout<<szoveg<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<","<<endl;
    };
    cout<<endl<<endl;
};

