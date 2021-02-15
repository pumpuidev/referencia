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
        vector<string> stringek;
        string sv;
        while(ss>>sv && !isdigit(sv[0]))
        {
            stringek.push_back(sv);     //gyujtom az elso szamig - az lesz a magassag
        }

        dx.nev = "";
        for(size_t i=0;i+1<stringek.size();++i) //osszerakom az utolso kivetelevel a beolvasott stringeket - ez a nev
        {
            dx.nev += " " + stringek[i];
        }
        dx.nev = dx.nev.substr(1);  //az elejen lett egy felesleges space, ezt elhagyom

        dx.faj = stringek[stringek.size() - 1]; //az utolso beolvasott string a faj
        dx.magassag = atoi(sv.c_str()); //az sv a magassag, hiszen az elso szamig olvastam

        dx.volt2014oltas = false;   //osszegzesnek alcazott linkerrel dontom el, volt-e 2014-es oltas
        dx.oltasok = 0;
        while(ss>>sv && "+" != sv)
        {
            ++dx.oltasok;
            dx.volt2014oltas = dx.volt2014oltas || "2014" == sv.substr(0,4);
        }
        dx.orokbefogadott = !ss.fail() && "+" == sv;
    }
}

Allat Enor::Current() const
{
    return dx;
}

bool Enor::End() const
{
    return vege;
}
