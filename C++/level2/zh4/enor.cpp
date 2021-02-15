#include "enor.h"
#include<cstdlib>
#include<iostream>
#include<sstream>

using namespace std;

Enor::Enor()
{
    x.open("f.txt");
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
    if(st == abnorm)
    {
        cout<<"ures"<<endl;
        exit(2);
    }
}

void Enor::Next()
{
    string sor;
    getline(x,sor);

    if(x.fail() || sor=="")
        st = abnorm;
    else
    {
        st = norm;

        //most a sorban bennvan a kovetkezo (most felsorolando) versenyzo adatainak sora mint string. Ezt kell feldarabolgatni
        //hat darabolgassuk fel, oszt pakoljuk bele egy vektorba
        istringstream ss(sor);
        string tempS;
        vector<string> tempV;
        tempV.resize(0);

        ss>>tempS;
        while(!ss.fail())
        {
            tempV.push_back(tempS);
            ss>>tempS;
        }

        //most benne van a temV-ben az osszes szoveg. Abbol az "elso nehany" a nev, aztan a csapat, aztan a korok.
        //keressuk meg az elso szamot benne!
        //kivalasztas tetel...
        size_t i=0;
        while(atoi(tempV[i].c_str()) == 0 && tempV[i] != "0") //amig 0-ra konvertalodik, pedig nem is az, azaz amig nem szam
            ++i;

        //most i-ben az elso szam indexe van. Azaz 0..i-2-ig van a nev
        dt.nev = "";
        for(size_t j=0;j+1<i;++j) //osszegzes tetel
            dt.nev = dt.nev + tempV[j] + " "; //ez meg a legutolso utan is rak egy space-t, de kicsire nem adunk :)

        dt.csapat = tempV[i-1]; //i-1 a csapat, EF: i>0

        //es akkor i-tol mennek a korok
        dt.koridok.clear();
        for(size_t j=i;j<tempV.size();j+=2)
        {
            koridoAdat k;
            k.sorszam = atoi(tempV[j].c_str());
            k.ido = tempV[j+1];
            dt.koridok.push_back(k);
        }
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
