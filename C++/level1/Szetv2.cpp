
//Feladat: Fagymentes és hideg napok szétválogatása

#include <iostream>

using namespace std;

void beolvasas(const int N,int X[]);
void szetvalogatas(const int N,const int X[],int & Db,int Y[]);
void kiiras(const int N,const int X[],const int Db,const int Y[]);
int main()
{
    int N,Db;
    cout << "Szetvalogatas - fagymentes napok" << endl<<endl;
    do {
        cout<<"Hany elemu tombot hasznalunk?";
        cin>>N;
    }while (N<=0);
    int X[N],Y[N]; //dinamikusan meretezett tömbök;
    beolvasas(N,X); //bemeneti tömb - hõmérsékletek sorozata
    szetvalogatas(N,X,Db,Y);
    kiiras(N,X,Db,Y); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,int X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". homersekletet:";
            cin>>X[i];
    };
}
void szetvalogatas(const int N,const int X[],int & Db,int Y[]){
    int Dbz=N;  //indextartomány transzformálása miatt
    Db=0;
    for (int i=0;i<N;++i){
        if (X[i]>0){
            Y[Db]=i;++Db;
        }
        else {
            Dbz--;Y[Dbz]=i;;
        }
    };
};
void kiiras(const int N,const int X[],const int Db,const int Y[]){
    cout<<"A homersekletek:"<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl;
    cout<<Db<<" szamu fagymentes nap volt, amely(ek) sorszama:";
    for (int i1=0;i1<Db;++i1){
        cout<<Y[i1]<<", ";
    };
    cout<<endl;
    cout<<N-Db<<" szamu fagymentes nap volt, amely(ek) sorszama:";
    for (int i2=Db;i2<N;++i2){
        cout<<Y[i2]<<", ";
    };
    cout<<endl;
};

