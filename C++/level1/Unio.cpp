
//Feladat: Minden mad�r, amit ak�r t�len, ak�r ny�ron megfigyelhet�ek

#include <iostream>

using namespace std;

void beolvasas(const int N,string X[]);
void unio(const int N,const string X[],const int M,const string Y[],int & Db, string Z[]);
void kiiras(const int N,const string X[],const int M,const string Y[],const int Db,const string Z[]);
int main()
{
    int N,M,Db,max;
    cout << "Minden madar, ami akar telen, akar nyaron megfigyelhetoek" << endl<<endl;
    do {
        cout<<"Hany teli madarat figyeltunk meg?";
        cin>>N;
    }while (N<=0);
    string X[N]; //dinamikusan meretezett t�mb, telen megfigyelt madarak;
    cout<<"Adja meg a telen megfigyelheto madarakat!"<<endl;
    beolvasas(N,X); //bemeneti t�mb - h�m�rs�kletek sorozata
    do {
        cout<<"Hany nyari madarat figyeltunk meg?";
        cin>>M;
    }while (M<=0);
    string Y[M]; //dinamikusan meretezett t�mb, telen megfigyelt madarak;
    cout<<"Adja meg a nyaron megfigyelheto madarakat!"<<endl;
    beolvasas(M,Y); //bemeneti t�mb - h�m�rs�kletek sorozata
    string Z[N+M];
    unio(N,X,M,Y,Db,Z);
   cout<<"A telen elofordulo madarak:"<<endl;

    kiiras(N,X,M,Y,Db,Z); //eredm�ny ki�r�sa
    return 0;
}
void beolvasas(const int N,string X[]){
    for (int i=0;i<N;++i){
            cout<<"Kerem az "<<i<<". madar nevet:";
            cin>>X[i];
    };
}
void unio(const int N,const string X[],const int M,const string Y[],int & Db,string Z[]){

    for (int i=0;i<N;++i){
        Z[i]=X[i]; //�tm�soljuk az X -belieket Z-be
    };
    int i1;
    Db=N;
    for (int j=0;j<M;++j){
        i1=0;
        while ((i1<N)&&(X[i1].compare(Y[j])!=0)){
            ++i1;
        }
        if (i1>=N){
            Z[Db]=Y[j];
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
    for (int i1=0;i1<M;++i1){
        cout<<Y[i1]<<", ";
    };
    cout<<endl;
    cout<<"Osszesen "<<Db<<" db kulonbozo madar fordul elo :";
    for (int i2=0;i2<Db;++i2){
        cout<<Z[i2]<<", ";
    };
    cout<<endl;
};

