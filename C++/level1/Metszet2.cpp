
//Feladat: Télen és nyáron is megfigyelhetõ madarak

#include <iostream>

using namespace std;

void beolvasas(const int N,string X[]);
void metszet(const int N,const string X[],const int M,const string Y[],int & Db, string Z[]);
void kiiras(const int N,const string X[],const int M,const string Y[],const int Db,const string Z[]);
int main()
{
    int N,M,Db,min;
    cout << "Telen es nyaron is megfigyelheto madarak" << endl<<endl;
    do {
        cout<<"Hany teli madarat figyeltunk meg?";
        cin>>N;
    }while (N<=0);
    string X[N]; //dinamikusan meretezett tömb, telen megfigyelt madarak;
    cout<<"Adja meg a telen megfigyelheto madarakat!"<<endl;
    beolvasas(N,X); //bemeneti tömb - hõmérsékletek sorozata
    do {
        cout<<"Hany nyari madarat figyeltunk meg?";
        cin>>M;
    }while (M<=0);
    string Y[M]; //dinamikusan meretezett tömb, telen megfigyelt madarak;
    cout<<"Adja meg a nyaron megfigyelheto madarakat!"<<endl;
    beolvasas(M,Y); //bemeneti tömb - hõmérsékletek sorozata
    if (N<M){min=N;}else{min=M;}; //min=N<M?N:M;
    string Z[min];
    metszet(N,X,M,Y,Db,Z);
    kiiras(N,X,M,Y,Db,Z); //eredmény kiírása
    return 0;
}
void beolvasas(const int N,string X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". madar nevet:";
            cin>>X[i];
    };
}
void metszet(const int N,const string X[],const int M,const string Y[],int & Db,string Z[]){
    int j;
    Db=0;
    for (int i=0;i<N;++i){
        j=0;
        while ((j<M)&&(X[i].compare(Y[j])!=0)){
            ++j;
        }
        if (j<M){
            Z[Db]=X[i];
            Db++;
        }
    };
};
void kiiras(const int N,const string X[],const int M,const string Y[],const int Db,const string Z[]){

    cout<<"A telen elofordulo madarak:"<<endl;
    for (int i=0;i<N;++i){
        cout<<X[i]<<",";
    };
    cout<<endl;
    cout<<"A nyaron elofordulo madarak:"<<endl;
    for (int i1=0;i1<Db;++i1){
        cout<<Y[i1]<<", ";
    };
    cout<<endl;
    cout<<Db<<" szamu telen es nyaron is megfigyelheto madar van:";
    for (int i2=0;i2<Db;++i2){
        cout<<Z[i2]<<", ";
    };
    cout<<endl;
};

