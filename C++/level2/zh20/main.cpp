#include <iostream>
#include "enor.h"

using namespace std;

bool volt7E(vector<Utazas> u);

int main()
{
    Enor t("be.txt");
    if(t.End())
    {
        cerr<<"Hibas file."<<endl;
    }
    else
    {
        t.First();
        if(!t.End())
        {
            Utas u = t.Current();
            //kiiras
//                cout<<"\""<<u.nev<<"\" "<<u.azonosito;
//                for(size_t i = 0;i<u.utazasok.size();++i)
//                    cout<<" ("<<u.utazasok[i].idokod<<", "<<u.utazasok[i].jaratszam<<")";
//                cout<<endl;

            //maxkiv
            int max = u.utazasok.size();
            Utas legtobbet = u;

            //linker - osszegzesnek alcazva
            bool l = volt7E(u.utazasok);    //eredetileg ez false-kent indulna, amihez a First utan hozzavagyolom a Current beta szerinti kepet, abbol meg ez lesz

            for(t.Next();!t.End();t.Next())
            {
                Utas u = t.Current();

                //kiiras
//                cout<<"\""<<u.nev<<"\" "<<u.azonosito;
//                for(size_t i = 0;i<u.utazasok.size();++i)
//                    cout<<" ("<<u.utazasok[i].idokod<<", "<<u.utazasok[i].jaratszam<<")";
//                cout<<endl;

                //maxkiv
                if(u.utazasok.size() > max)
                {
                    max = u.utazasok.size();
                    legtobbet = u;
                }

                //linker
                l = l || volt7E(u.utazasok);
            }
            cout<<"A legtobbet utazo utas "<<legtobbet.nev<<" ("<<legtobbet.azonosito<<") volt, "<<legtobbet.utazasok.size()<<" utazassal."<<endl;

            if(l)
                cout<<"Volt 7E-vel jaro utas"<<endl;
            else
                cout<<"Nem volt 7E-vel jaro utas"<<endl;
        }
        else
        {
            cerr<<"A fajl ures, nincs \"legtobbet\" utazo utas."<<endl;

            cout<<"Nem volt 7E-vel jaro utas"<<endl;    //a linker ures file-ra is ertelmes...
        }
    }

    return 0;
}

bool volt7E(vector<Utazas> u)
{
    bool l = false;
    for(size_t i = 0;!l && i<u.size();++i)
        l = "7E" == u[i].jaratszam;
    return l;
}
