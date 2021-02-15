#include "enor.h"
#include<cstdlib>
#include<iostream>
#include<sstream>

using namespace std;

Enor::Enor(string nev)
{
    x.open(nev.c_str());
    if(x.fail())
    {
        cout<<"fajlmegnyitasi hiba"<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    Next();
}

void Enor::Next()
{
    string sor;
    getline(x,sor);

    if(x.fail())
        st = abnorm;
    else
    {
        //szokasos eljaras. stringstream
        stringstream ss(sor);
        ss>>dt.nev;
        string temp;
        ss>>temp; //csapatot eldobjuk

        double osszeg = 0.0; //osszegzes
        double darab = 0.0; //szamlalas
        ss>>temp; //beolvastuk az elso sorszamot, a ciklus megmondja, volt-e...
        while(!ss.fail())
        {
            ss>>temp; //a beolvasott sorszamhoz rendelt ido.
            osszeg += atof(temp.c_str());
            ++darab;
            ss>>temp; //kovetkezo elem sorszamat kisereljuk meg beolvasni
        }

        if(darab!=0)
            dt.atlagosIdo = osszeg / darab;
        else
            dt.atlagosIdo = 0.0;
    }
}

bool Enor::End()
{
    return st == abnorm;
}

Elem Enor::Current()
{
    return dt;
}
