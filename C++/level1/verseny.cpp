#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MaxN=100;
struct AdatT{
    string nev;
    int ind;
    int erk;
    int kul;
};

void beolvFilebol(char * filename,int &N, AdatT adatok[]);
void beolvKonzolrol(int &N, AdatT adatok[]);
void kikHianyoznak(int N,const AdatT adatok[],int &elvDB,int elvek[]);
int kiNyert(int N,const AdatT adatok[]);

int main(int argc, char * argv[])
{
    cerr << "Verseny" << endl;

    //Deklaráció (spec be/ki-bõl típusok és változók)
    int N;
    AdatT adatok[MaxN];

    int nyert;
    int elvDB;
    int elvek[MaxN];

    if (argc>1) {
        beolvFilebol(argv[1],N,adatok);
    } else {
        beolvKonzolrol(N,adatok);
    }

    kikHianyoznak(N,adatok,elvDB,elvek);
    nyert=kiNyert(N,adatok);

    cerr << "A nyertes sorszama: ";
    cout << nyert << endl;

    cout << elvDB;
    cerr << "-an vesztek el. Sorszamaik:" << endl;
    for (int i=0; i<elvDB; i++) {
        cout << " " << elvek[i];
    }
    cout << endl;


    return 0;
}

void beolvFilebol(char * filename,int &N, AdatT adatok[]){
    //if (nemJO) {exit(1);}
}

void beolvKonzolrol(int &N, AdatT adatok[]){
    //do{ }while(nemJO);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> adatok[i].nev;
        cin >> adatok[i].ind;
        cin >> adatok[i].erk;
        adatok[i].kul=adatok[i].erk-adatok[i].ind;
    }
}

void kikHianyoznak(int N,const AdatT adatok[],int &elvDB,int elvek[]){
    elvDB=0;
    for (int i=0;i<N;i++) {
        if (adatok[i].kul<=0) {
            elvek[elvDB]=i+1;
            elvDB++;
        }
    }
}

int kiNyert(int N,const AdatT adatok[]){
    int nyert=0;
    return nyert+1;
}
