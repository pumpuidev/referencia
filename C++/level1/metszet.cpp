#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ttanulok{
    string nev;
    int jegy;
};
const int maxn=10;
char f1[20],f2[20];
int n,m,db;
ttanulok zh[maxn];
ttanulok potzh[maxn];
ttanulok metszet[maxn];

void beolvas(ttanulok tomb[],int&szam,string strg)
{
    char fnev[20];
    cout<<strg;
    cin>>fnev;
    ifstream input(fnev,ios::in);
    if(input.is_open()){
        input>>szam;
        for(int i=0;i<szam;++i){
            input>>tomb[i].nev;
            input>>tomb[i].jegy;
        }
    }

    for(int i=0;i<szam;++i){
        cout<<tomb[i].nev<<endl;
    }

    input.close();
};

void metszetf(ttanulok x[],ttanulok y[],ttanulok z[],const int n,const int m,int&db){
    db=0;
    int j;
    for(int i=0;i<n;++i){
        j=0;
        while((j<m)&&(!(strcmp(x[i].nev.c_str(),y[i].nev.c_str())==0))){
            ++j;
        }
        if(j<m){
            z[db].nev=x[i].nev;
            ++db;
        }
    }
}

void kiir(ttanulok tomb[],const int szam){
    ofstream output("metszett.ki",ios::out);
    for(int i=0;i<szam;++i){
        output<<tomb[i].nev<<endl;
    }
}

int main()
{
    beolvas(zh,n,"zh fajl: ");
    beolvas(potzh,m,"potzh fajl: ");
    metszetf(zh,potzh,metszet,n,m,db);
    kiir(metszet,db);
}
