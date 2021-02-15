#include <iostream>
#include "enor.h"

using namespace std;


bool nem1577(const vector<string> &csatak);

int main()
{
    Enor t("be.txt");

    int spanyolok = 0;  //szamlalas

    bool vanazsiai = false; //feltmaxker
    Sziget minsziget;
    int min;

    bool nemcsatazott = true;   //igaz-e, hogy nem csatazott 1577-ben ==> "minden" csata nem 1577-ben volt ==> optlinker,
                                //DE osszegzeskent oldom meg, hogy azonos legyen a ciklus alakja

    for(t.First(); !t.End(); t.Next())
    {
        Sziget e = t.Current();

        //ellenorzes
//        cout<<"\""<<e.nev<<"\""<<" "<<e.kont<<" "<<e.sereg; //idezojelekbe raktam a nevet, hogy lassuk, tenyleg addig tart-e, mint kell
//        for(size_t i=0;i<e.csatak.size();++i)
//        {
//            cout<<" "<<e.csatak[i];
//        }
//        cout<<" "<<e.birtoklo;
//        cout<<endl;

        //szamlalas
        if("Spanyolo." == e.birtoklo && 5 > e.sereg)
        {
            ++spanyolok;
        }

        //feltmaxker
        if("Azsia" == e.kont)
        {
            if(vanazsiai)
            {
                if(min > e.csatak.size())
                {
                    min = e.csatak.size();
                    minsziget = e;
                }
            }
            else
            {
                vanazsiai = true;
                min = e.csatak.size();
                minsziget = e;
            }
        }

        //optlinker osszegzessel (H ~ L; + ~ es; 0 ~ true)
        nemcsatazott = nemcsatazott && nem1577(e.csatak);
    }

    cout<<"A spanyol uralmu, 500 fo alatti helyorseggel rendelkezo szigetek szama: "<<spanyolok<<"."<<endl;
    if(vanazsiai)
    {
        cout<<"A legbekesebb azsiai sziget: "<<minsziget.nev<<"."<<endl;
    }
    else
    {
        cout<<"Nincs azsiai sziget."<<endl;
    }

    if(nemcsatazott)
    {
        cout<<"Nem csatazott 1577-ben."<<endl;
    }
    else
    {
        cout<<"Csatazott 1577-ben."<<endl;
    }

    return 0;
}

//itt azt nezem meg, egy adott szigethez tartozo minden csata "nem 1577-ben" volt-e
//ez is optlinker, ezt mar megirom hagyomanyos optlinker alakban
bool nem1577(const vector<string> &csatak)
{
    bool l = true;
    for(size_t i=0; l && i<csatak.size(); ++i)
    {
        l = "1576.12.31." >= csatak[i] || "1578.01.01." <= csatak[i];   //vagy korabbi, vagy kesobbi
    }
    return l;
}
