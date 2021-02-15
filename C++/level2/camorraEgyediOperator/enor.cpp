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
    x>>akt;
    if(x.fail())
        vege = true;
}

ostream& operator<<(ostream &os, const Adat &a)
{
    os<<a.nev<<" "<<a.mind10alatt<<" "<<a.vankonk;

    return os;
}

istream& operator>>(istream &is, Adat &a)
{
    string sor;
    getline(is,sor);
    if(!is.fail())
    {
        stringstream ss(sor);

        ss>>a.nev;

        a.mind10alatt = true;
        for(int i=0;i<10;++i)
        {
            int n;
            ss>>n;
            a.mind10alatt &= n<10;
        }

        string konk;
        ss>>konk;
        if(konk == "van")
            a.vankonk = true;
        else
            a.vankonk = false;
    }

    return is;
}
