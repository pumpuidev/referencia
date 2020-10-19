#include <iostream>
#include <cstdlib>
/*Prorok Ernest
Filspa
hbv
ernest.prorok@gmail.com */
using namespace std;

int main()
{
    int sorszam1,sorszam2;
    int csere;
    cout<<"elso versenyzo sorszama: ";
    cin>>sorszam1;

    if ((sorszam1<1) || (sorszam1>30)){
        cout<<"Egyes versenyzo sorszama nem 1 es 30 kozotti";
        exit(1);
    }
    cout<<"masodik versenyzo sorszama: ";
    cin>>sorszam2;
    if ((sorszam2<1) || (sorszam2>30) || (sorszam1==sorszam2)){
        if (sorszam1==sorszam2){
            cout<<"Azonos a versenyzok sorszama";
            exit(2);}
        cout<<"Masodik versenyzo sorszama nem 1 es 30 kozotti";
        exit(1);
    }

    csere=sorszam1;
    sorszam1=sorszam2;
    sorszam2=csere;

    cout<<"az uj sorrend: "<<sorszam1<<", "<<sorszam2/*<<"/n"*/;
    return 0;
}
