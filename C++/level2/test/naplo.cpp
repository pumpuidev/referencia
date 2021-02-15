
//Feladat:       Van-e minden tanul�nak legal�bb k�t tant�rgyb�l �t�se

#include "naplo.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "read.h"

using namespace std;

//Feladat: 	Megvizsg�lja, hogy mindenkinek van-e legal�bb k�t �t�se.

bool mindenkinek_ket_otos(const vector<vector<int> > &naplo)
{
    bool l = true;
    for( int i=0; l && i<(int)naplo.size(); ++i) {
        l = otosDb(naplo[i])>=2;
    }
    return l;
}

//Feladat: 	H�ny �t�se van egy tanul�nak.

int otosDb(const vector<int> &v)
{
    int s = 0;
    for(int j=0; j<(int)v.size(); ++j) {
        if (v[j]==5) ++s;
    }
    return s;
}

//Feladat: 	Nevekkel t�lt fel egy t�mb�t.

void neveket_olvas(int n, const string &msg, vector<string> &v)
{
    v.resize(n);
    for(int i=0; i<n; ++i)
    {
        cout << i+1 << "." << msg << "neve: ";
        cin >> v[i];
    }
}

//Feladat: 	1 �s 5 k�z�tti sz�mokkal t�lt fel egy m�trixot.

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
            a[i][j] = read_int("","1 �s 5 kozotti szamot kerek!", jegy);
        }
    }
}

//Feladat: 	Tanul� �s tant�rgy neveket olvas egy sz�veges �llom�nyb�l,

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

//Feladat: 	Eld�nti egy eg�sz sz�mr�l, hogy oszt�lyzat-e.

bool jegy(int k)
{
    return 1<=k && k<=5;
}

//Feladat: 	Eld�nti egy eg�sz sz�mr�l, hogy 1, 2 vagy 3 �rt�k�-e.

bool egykettoharom(int k)
{
    return k>=1 && k<=3;
}
