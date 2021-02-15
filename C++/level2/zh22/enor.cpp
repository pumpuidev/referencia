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

bool Enor::End() const
{
    return vege;
}

Film Enor::Current() const
{
    return dx;
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

        dx.nev = "";
        string sv,sv2;
        ss>>sv;
        while(ss>>sv2 && !ido(sv2))
        {
            dx.nev += " " + sv;
            sv = sv2;
        }
        dx.nev = dx.nev.substr(1);

        dx.terem = sv;
        dx.ido = sv2;

        //szamlalas tetelek
        dx.g = 0;
        dx.d = 0;
        dx.f = 0;
        string seged;
        while(ss>>seged)
        {
            if("G" == seged)
                ++dx.g;
            else if("D" == seged)
                ++dx.d;
            else if("F" == seged)
                ++dx.f;
        }
    }
}

bool Enor::ido(std::string s)
{
    return 5 == s.length() &&
            isdigit(s[0]) &&
            isdigit(s[1]) &&
            ':' == s[2] &&
            isdigit(s[3]) &&
            isdigit(s[4]);
}
