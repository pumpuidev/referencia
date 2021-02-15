#include "enor.h"
#include <cstdlib>
#include <sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"Hibas v. nem letezo file."<<endl;
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
        ss>>akt.datum>>akt.vkod;

        akt.aruk.clear();
        string sv;
        while(ss>>sv)
            akt.aruk.push_back(sv);
    }
}
