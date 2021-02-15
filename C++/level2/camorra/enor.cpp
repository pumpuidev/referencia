#include"enor.h"
#include<cstdlib>
#include<sstream>

using namespace std;

Enor::Enor(string nev)
{
    x.open(nev.c_str());
    if(x.fail())
    {
        cerr<<"Hibas file!"<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::Next()
 {
    string sor;
    getline(x,sor);

    if(x.fail())
        vege = true;
    else
    {
        stringstream ss(sor);
        ss>>akt.nev;
        akt.penz.resize(0);
        for(int i=0;i<10;++i)
        {
            int n;
            ss>>n;
            akt.penz.push_back(n);
        }
        ss>>akt.konk;
    }
 }
