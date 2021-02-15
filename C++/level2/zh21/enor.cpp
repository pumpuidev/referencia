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
    getline(x,sor);
    if(x.fail())
    {
        vege = true;
    }
    else
    {
        stringstream ss(sor);

        //itt nem volt expliciten kerve, hogy irjuk ki a nevet, ezert inkabb be se olvasom, csak eldobom :D
        string sv;
        while(ss>>sv && !isdigit(sv[0]));   //pontosvesszo : ures torzsu ciklus!

        dx.azonosito = sv;  //az elso szam

        dx.utazasok = 0;    //szamlalas nullazasa

        dx.legkorabbi = "";
        ss>>sv;
        if(!ss.fail())      //elso elem letezik-e?
        {
            ++dx.utazasok;  //ha letezik, novelem ezt

            dx.legkorabbi = sv;
            ss>>sv;

            while(ss>>sv)   //kov. elem letezik-e?
            {
                ++dx.utazasok;  //ha letezik, novelem ezt

                if(sv < dx.legkorabbi)
                {
                    dx.legkorabbi = sv;
                }
                ss>>sv;
            }
        }
    }
}

bool Enor::End() const
{
    return vege;
}

Utas Enor::Current() const
{
    return dx;
}
