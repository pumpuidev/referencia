
//Feladat:       Van-e minden tanulónak legalább két tantárgyból ötöse

#include "naplo.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "read.h"

using namespace std;

//Feladat: 	Megvizsgálja, hogy mindenkinek van-e legalább két ötöse.

bool mindenkinek_ket_otos(const vector<vector<int> > &naplo)
{
    bool l = true;
    for( int i=0; l && i<(int)naplo.size(); ++i) {
        l = otosDb(naplo[i])>=2;
    }
    return l;
}

//Feladat: 	Hány ötöse van egy tanulónak.

int otosDb(const vector<int> &v)
{
    int s = 0;
    for(int j=0; j<(int)v.size(); ++j) {
        if (v[j]==5) ++s;
    }
    return s;
}

//Feladat: 	Nevekkel tölt fel egy tömböt.

void neveket_olvas(int n, const string &msg, vector<string> &v)
{
    v.resize(n);
    for(int i=0; i<n; ++i)
    {
        cout << i+1 << "." << msg << "neve: ";
        cin >> v[i];
    }
}

//Feladat: 	1 és 5 közötti számokkal tölt fel egy mátrixot.

void jegyeket_olvas(const vector<string> &tanulo, const vector<string> &targy, vector<vector<int> > &a)
{
    a.resize((int)tanulo.size());
    for(int i=0; i<(int)tanulo.size(); ++i)
    {
        a[i].resize((int)targy.size());
        cout << tanulo[i] << " eredmenyei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            cout << "\t" << targy[j] << ": ";
            a[i][j] = read_int("","1 és 5 kozotti szamot kerek!", jegy);
        }
    }
}

//Feladat: 	Tanuló és tantárgy neveket olvas egy szöveges állományból,

void fajlbol_olvas(const string &fajlnev, vector<string> &tanulo, vector<string> &targy, vector<vector<int> > &naplo)
{
    ifstream f(fajlnev.c_str());
    if(f.fail()){
        cout << "Hibas fajlnev!\n";
        exit(1);
    }

    int n, m;
    f >> n >> m;
    string str;
    getline(f, str, '\n');

    cout << "\nTanulok:\n";
    tanulo.resize(n);
    for(int i=0; i<n; ++i)
    {
        getline(f, tanulo[i], '\n');
        cout << tanulo[i] << endl;
    }

    cout << "\nTargyak:\n";
    targy.resize(m);
    for(int j=0; j<m; ++j)
    {
        f >> targy[j];
        cout << targy[j] << endl;
    }

    cout << "\nNaplo:\n";
    naplo.resize(n);
    for(int i=0; i<(int)tanulo.size(); ++i)
    {
        naplo[i].resize(m);
        cout << tanulo[i] << " eredmenyei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            f >> naplo[i][j];
            cout << "\t" << targy[j] << ": " << naplo[i][j];
        }
        cout << endl;
    }
}

//Feladat: 	Eldönti egy egész számról, hogy osztályzat-e.

bool jegy(int k)
{
    return 1<=k && k<=5;
}

//Feladat: 	Eldönti egy egész számról, hogy 1, 2 vagy 3 értékû-e.

bool egykettoharom(int k)
{
    return k>=1 && k<=3;
}
