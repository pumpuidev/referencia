#include"enor.h"
#include<cstdlib>
#include<sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"Mijau."<<endl;
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
        if(sor != "")
        {
            stringstream ss(sor);
            string eldobni;			//mert a kor nem is fontos most
            ss>>akt.nev>>eldobni;

            int c=0;
            string s;
            while(ss>>s)			//megszamlaljuk meg hany szo van...
                ++c;

            akt.szin = s;			//az utolso a szin...
            akt.kolykokSzama = c-1;	//az osszes tobbiek a kolykok
        }
        else
            Next();
    }
}
