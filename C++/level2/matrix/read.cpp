//Feladat:      segédfüggvények számok billentyûzetrõl való beolvasásához

#include "read.h"
#include <iostream>

using namespace std;

bool all(int n){ return true; }
bool nat(int n){ return n>=0; }

bool all(double r){ return true;}
bool not_neg(double r){ return r>=0; }

int read_int(const string &msg, const string &err, bool valid(int))
{
    int n;
    bool hiba;
    do{
        cout << msg;
        cin >> n;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0 || !valid(n);
        if(hiba) cout << err << endl;
    }while(hiba);

    return n;
}

double  read_real(const string &msg, const string &err, bool valid(double))
{
    double a;
    string tmp;
    bool hiba;
    do{
        cout << msg;
        cin >> a;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0 || !valid(a);
        if(hiba) cout << err << endl;

    }while(hiba);

    return a;
}
