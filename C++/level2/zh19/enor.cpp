#include "enor.h"
#include <sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
        sx = Abnorm;
    else
        sx = Norm;
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
    if(getline(x,sor))
    {
        stringstream ss(sor);

        dx.nev = "";    //mivel ismetelt hozzakonkatenalgatas eredmenye lesz a nev, epp mint a vectorokat, ezt is nullazni kell ket kor kozott
        string sv;
        while(ss>>sv && !isdigit(sv[0]))    //elso szamig megyunk, addig osszerakjuk a nevet
        {
            dx.nev += " " + sv;
        }
        dx.nev = dx.nev.substr(1);  //volt az elejen egy felesleges szokoz

        dx.chip = sv;   //o volt az elso szam, azaz o a chip-kod

        //innen ugyanaz:
        dx.eredmenyek.clear();
        Eredmeny e;
        while(ss>>e.szorzo)
        {
            ss>>e.pont;
            dx.eredmenyek.push_back(e);
        }
    }
    else
    {
        sx = Abnorm;
    }
}

Kutymuty Enor::Current() const
{
    return dx;
}

bool Enor::End() const
{
    return Abnorm == sx;
}
