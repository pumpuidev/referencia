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
    getline(x,sor);
    if(x.fail())
    {
        sx = Abnorm;
    }
    else
    {
        stringstream ss(sor);

        dx.nev = "";
        string sv;
        while(ss>>sv && !isdigit(sv[0]))
            dx.nev += " " + sv;
        dx.nev = dx.nev.substr(1);

        dx.azonosito = sv;

        //innen ugyanaz
        Utazas u;
        dx.utazasok.clear();
        while(ss>>u.idokod)
        {
            ss>>u.jaratszam;
            dx.utazasok.push_back(u);
        }
    }
}

bool Enor::End() const
{
    return Abnorm == sx;
}

Utas Enor::Current() const
{
    return dx;
}
