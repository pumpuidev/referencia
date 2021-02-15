#include "enor.h"
#include <sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    vege = x.fail();
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

        string sv;
        dx.nev = "";
        while(ss>>sv && !isdigit(sv[0]))    //beolvasas szamig
        {
            dx.nev += " " + sv;
        }
        dx.nev = dx.nev.substr(1);

        dx.chip = sv;   //ez az a szam

        dx.osszpont = 0;    //osszegzes
        dx.sikeres = true;
        int szorzo;
        while(ss>>szorzo)
        {
            int pont;    //ehhez mar ket segedvaltozo kellett
            ss>>pont;
            dx.sikeres = dx.sikeres && 0 != pont;
            dx.osszpont += szorzo * pont;   //osszegzes
        }
    }
    else
    {
        vege = true;
    }
}

Kutymuty Enor::Current() const
{
    return dx;
}

bool Enor::End() const
{
    return vege;
}
