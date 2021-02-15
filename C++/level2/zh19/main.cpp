#include <iostream>
#include "enor.h"

using namespace std;

bool vanSikertelen(const vector<Eredmeny> &e);
int osszpont(const vector<Eredmeny> &e);

int main()
{
    Enor t("be.txt");
    if(t.End())
    {
        cerr<<"Nem letezo file :("<<endl;
    }
    else
    {
        int elsoDijasok = 0;
        int masodikDijasok = 0;
        for(t.First();!t.End();t.Next())
        {
            Kutymuty k = t.Current();

            //ellenorzes:
//            cout<<k.chip<<" \""<<k.nev<<"\"";
//            for(size_t i=0;i<k.eredmenyek.size();++i)
//                cout<<" ("<<k.eredmenyek[i].szorzo<<" * "<<k.eredmenyek[i].pont<<")";
//            cout<<" pont: "<<osszpont(k.eredmenyek);
//            cout<<endl;

            if(vanSikertelen(k.eredmenyek))
                cout<<k.nev<<" - "<<k.chip<<endl;

            int s = osszpont(k.eredmenyek);
            if(s > 85)
                ++elsoDijasok;
            if(s > 70 && s <= 85)
                ++masodikDijasok;
        }
        cout<<"I. dijasok: "<<elsoDijasok<<"."<<endl;
        cout<<"II. dijasok: "<<masodikDijasok<<"."<<endl;
    }

    return 0;
}

//pesszimista linearis kereses
//beta(e) - 0 == e.pont (felfoghato lett volna ugy is, hogy a szorzat 0, de valoszinuleg a szorzo sose lesz 0, tehat ez u.a.)
//elem elhagyva
//l - l
bool vanSikertelen(const vector<Eredmeny> &e)
{
    bool l = false;
    for(size_t i=0;!l && i<e.size();++i)
        l = 0 == e[i].pont;
    return l;
}

//osszegzes
//s - s
//f - az akt. elem szorzojanak es pontjanak szorzata
//(H,+,0) - (N,+,0)
int osszpont(const vector<Eredmeny> &e)
{
    int s = 0;
    for(size_t i=0;i<e.size();++i)
        s += e[i].szorzo * e[i].pont;
    return s;
}
