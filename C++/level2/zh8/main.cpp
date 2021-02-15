#include <iostream>
#include "enor.h"

using namespace std;


int main()
{
    Enor t("be.txt");

    int szomoruOroszlanok = 0;  //szamlalas

    bool vanKicsi = false; //feltmaxker
    Allat legtobbszorOltott;
    int max;

    bool nemMindenkit2014ben = false;   //nem mindekit oltottak be 2014-ben ==> van olyan, akit nem ==> linker

    for(t.First(); !t.End(); t.Next())
    {
        Allat e = t.Current();

        //ellenorzes
//        cout<<"\""<<e.nev<<"\""<<" "<<e.faj<<" "<<e.magassag<<" "<<e.oltasok<<" "<<e.volt2014oltas<<" "<<e.orokbefogadott<<endl;
        //nev idezojelek kozott, hogy lathato legyen, hol van az eleje es a vege

        //szamlalas
        if("oroszlan" == e.faj && !e.orokbefogadott)
        {
            ++szomoruOroszlanok;
        }

        //feltmaxker
        if(200 > e.magassag)
        {
            if(vanKicsi)
            {
                if(max < e.oltasok)
                {
                    max = e.oltasok;
                    legtobbszorOltott = e;
                }
            }
            else
            {
                vanKicsi = true;
                max = e.oltasok;
                legtobbszorOltott = e;
            }
        }

        //linker
        nemMindenkit2014ben = nemMindenkit2014ben || !e.volt2014oltas;
    }

    cout<<"Az orokbe nem fogadott oroszlanok szama: "<<szomoruOroszlanok<<"."<<endl;
    if(vanKicsi)
    {
        cout<<"A legtobbszor oltott 2 m-nel alacsonyabb allat: "<<legtobbszorOltott.nev<<"."<<endl;
    }
    else
    {
        cout<<"Csak legalabb 2 m-es allatok vannak."<<endl;
    }
    if(nemMindenkit2014ben)
    {
        cout<<"Nem mindenkit oltottak be 2014-ben."<<endl;
    }
    else
    {
        cout<<"Mindenkit beoltottak 2014-ben."<<endl;
    }

    return 0;
}
