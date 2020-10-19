#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ttanulok{
    string nev;
    string szemszam;
};
const int maxn=10;

void beolvas(int&n,ttanulok tanulok[])
{
    cout<<"Adat fajl neve: ";
    char fnev[20];
    cin>>fnev;
    ifstream input(fnev,ios::in);
    if(input.is_open()){
        n=0;
        while(!input.eof()){
            input>>tanulok[n].nev;
            input.ignore(100,'\n');
            input>>tanulok[n].szemszam;
            input.ignore(100,'\n');
            n++;
        }
    }
    input.close();
}

void szetvalogat(const int n,const ttanulok tanulok[],int&db1,int tanulok2[])
{
    db1=0;
    int db2=n;
    for(int i=0;i<n;++i){
        if(tanulok[i].szemszam.at(0)=='1'){
            tanulok2[db1]=i;
            ++db1;
        }
        else{
            tanulok2[db2]=i;
            --db2;
        }
    }
}

void kiir(const int n,const ttanulok tanulok[],const int db1,const int tanulok2[])
{
    for(int i=0;i<db1;++i){
        cout<<tanulok[tanulok2[i]].nev<<" ";
    }
}

int main()
{
    int n,db1;
    ttanulok tanulok[maxn];
    int tanulok2[maxn];
    beolvas(n,tanulok);
    szetvalogat(n,tanulok,db1,tanulok2);
    kiir(n,tanulok,db1,tanulok2);
    return 0;
}
