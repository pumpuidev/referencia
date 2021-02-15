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

        akt.mind10alatt = true;
        for(int i=0;i<10;++i)
        {
            int n;
            ss>>n;
            akt.mind10alatt &= n<10;    //nem lehet sima opt.linker, mert most muszaj vegigolvasni az egeszet!
        }                               //hogy a "konk" valoban a 12. adat legyen!

        string konk;
        ss>>konk;
        if(konk == "van")
            akt.vankonk = true;
        else
            akt.vankonk = false;
    }
}
