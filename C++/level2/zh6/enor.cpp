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
    if(st==abnorm)
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
        //szokasos eljaras. stringstream
        stringstream ss(sor);
        ss>>dt.nev; //az elso szo biztos a nevben van

        string temp, temp2;
        ss>>temp; //aztan olvassuk a 2. szot
        ss>>temp2; //meg a 3-at...
        while(!ss.fail() && atoi(temp2.c_str()) == 0 && temp2 != "0") //addig megyunk, amig ez nem lesz szam.
        {
            dt.nev += " " + temp;
            temp = temp2;
            ss>>temp2;
        }

        //most a temp2-ben szam van, tempben az utolso nem szam (csapat), dt.nev pedig teljes!

        double osszeg = 0.0; //osszegzes
        double darab = 0.0; //szamlalas
        dt.novekvo = true; //osszegzes(!) ... nem lehet linker, mert most vegig kell menni az intervallumon a masik tetel miatt
        double elozo = 0.0; //segedvaltozo amiben az elozo koridot nezem. kezdetben ez kapott egy szelsoseges erteket, ami nyilvan nem lehet valodi korido.
        while(!ss.fail())
        {
            ss>>temp; //a beolvasott sorszamhoz rendelt ido.
            osszeg += atof(temp.c_str());
            ++darab;

            if(elozo != 0.0) //ha nem az elso korben vagyunk, akkor van elozo...
                dt.novekvo &= elozo>atof(temp.c_str()); //megnezzuk, l igaz maradt-e.
             elozo = atof(temp.c_str()); //tovabblepunk az elozo-vel is

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
