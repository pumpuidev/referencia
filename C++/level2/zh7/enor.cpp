#include "enor.h"
#include <cstdlib>
#include <sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"Hibas file"<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    vege = false;
    Next();
}

void Enor::Next()
{
    string sor;
    getline(x,sor);
    if(x.fail())
    {
        vege = true;
    }
    else
    {
        stringstream ss(sor);
        //tobb tagu nevek
        //mivel a nev utan van a kontinens, ami ugyanugy string,
        //ezert csak a helyorseg beolvasasa utan tudom megmondani, hol van vege a nevnek
        //ezert olvasok kettot elore
        dx.nev = "";
        string sv,sv2;
        ss>>sv;
        while(ss>>sv2 && !isdigit(sv2[0]))  //egeszen addig olvasok, amig nem szammal kezdodik az sv2 - az isdigit fv. karaktert var, nem stringet
        {
            dx.nev += sv + " "; //amig az sv MOGOTT levo dolog (sv2) se szam, addig az sv biztos nem az utolso string, azaz biztos a nev resze
            sv = sv2;   //elmentem a kov. korre az sv2-t, hiszen azt felul fogom irni a while felteteleben
        }
        dx.nev = dx.nev.substr(0, dx.nev.length() - 1); //levagom az utolso space-t
        dx.kont = sv;   //o volt az utolso string
        dx.sereg = atoi(sv2.c_str());   //o volt az elso szam

        //innen meg ugyanaz, mint eddig
        dx.csatak.clear();
        while(ss>>sv && datum(sv))
        {
            dx.csatak.push_back(sv);
        }
        if(ss.fail())
        {
            dx.birtoklo = "";
        }
        else
        {
            dx.birtoklo = sv;
        }
    }
}

bool Enor::datum(string s)
{
    return 11 == s.length() &&
          isdigit(s[0]) &&
          isdigit(s[1]) &&
          isdigit(s[2]) &&
          isdigit(s[3]) &&
          '.' == s[4] &&
          isdigit(s[5]) &&
          isdigit(s[6]) &&
          '.' == s[7] &&
          isdigit(s[8]) &&
          isdigit(s[9]) &&
          '.' == s[10];
}

Sziget Enor::Current() const
{
    return dx;
}

bool Enor::End() const
{
    return vege;
}
