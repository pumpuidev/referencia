
//Feladat: Fagymentes és hideg napok szétválogatása

#include <iostream>

using namespace std;

void beolvasas(const int N,int X[]);
void szetvalogatas(const int N,const int X[],int & Db,int Y[],int Z[]);
void kiiras(const int N,const int X[],const int Db,const int Y[],const int Z[]);
int main()
{
    int N,Db;
    cout << "Szetvalogatas - fagymentes napok" << endl<<endl;
    do {
        cout<<"Hany elemu tombot hasznalunk?";
        cin>>N;
    }while (N<=0);
    int X[N],Y[N],Z[N]; //dinamikusan meretezett tömbök;
    beolvasas(N,X); //bemeneti tömb - hõmérsékletek sorozata
    szetvalogatas(N,X,Db,Y,Z);
    kiiras(N,X,Db,Y,Z); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,int X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". homersekletet:";
            cin>>X[i];
    };
}
void szetvalogatas(const int N,const int X[],int & Db,int Y[],int Z[]){
    int Dbz=0;
    Db=0;
    for (int i=0;i<N;++i){
        if (X[i]>0){
            Y[Db]=i;++Db;
        }
        else {
            Z[Dbz]=i;Dbz++;
        }
    };
};
void kiiras(const int N,const int X[],const int Db,const int Y[],const int Z[]){
    cout<<"A homersekletek:"<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl;
    cout<<Db<<" szamu fagymentes nap volt, amelyek sorszama:";
    for (int i1=0;i1<Db;++i1){
        cout<<Y[i1]<<", ";
    };
    cout<<endl;
    cout<<N-Db<<" szamu fagymentes nap volt, amelyek sorszama:";
    for (int i2=0;i2<N-Db;++i2){
        cout<<Z[i2]<<", ";
    };
    cout<<endl;
};
