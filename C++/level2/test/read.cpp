
//Feladat:   segédfüggvény egésszámok billentyûzetrõl való beolvasásához

#include "read.h"
#include <iostream>

using namespace std;

bool all(int k) {return true;}
bool nat(int k) {return k>=0;}
bool neg(int k) {return k<0;}

//Feladat: 	Megadott feltételt kielégítő egész számot olvas be.

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
