#include <iostream>
#include<sstream>
#include<cstdlib>
#include "enor.h"

using namespace std;

bool betaSzamlalas(Elem e);
bool betaMaxker(Elem e);
string tizedikkor(Elem e);
string versenyzo(Elem e);

int main()
{
    //szamlalas & feltmaxker felsorolora
    Enor t;
    int c = 0;
    int l = false;
    string maxertek;
    Elem maxelem;
    for(t.First();!t.End();t.Next())
    {
        if(betaSzamlalas(t.Current()))
            ++c;
        if(betaMaxker(t.Current())) //ha volt 10. kor
        {
            if(l)
            {
                if(maxertek>tizedikkor(t.Current()))
                {
                    maxertek = tizedikkor(t.Current());
                    maxelem = t.Current();
                }
            }
            else
            {
                l=true;
                maxertek = tizedikkor(t.Current());
                maxelem = t.Current();
            }
        }
    }

    cout<<"Ennyinek volt masfelnel jobb a korideje: "<<c<<endl;
    if(l)
        cout<<"A legjobb koridot a 10. korben: "<<versenyzo(maxelem)<<" futotta."<<endl;
    else
        cout<<"Nem volt 10. mert kor."<<endl;

    return 0;
}

bool betaSzamlalas(Elem e) //az e-ben van egy szoveg ami a versenyzorol minden adatot tartalmaz (e.sor)
{
    istringstream ss(e.sor);
    string tmp;
    ss>>tmp; //eldobom az elejerol a stringeket
    while(!ss.fail() && atoi(tmp.c_str())==0 && tmp != "0")
        ss>>tmp;

    //itt most tmp-ben ott van a korsorszam
    bool l = false; //kerdes: van-e masfelnel gyorsabb, ez egy (pessz) linker...
    while(!ss.fail() && !l) //amig nem l és nem End (nem ert veget a sor)
    {
        ss>>tmp; //addig beolvassuk az akt koridot
        l = tmp<"01:30:000"; //megnezzuk, igaz-e ra amit kerdezunk
        ss>>tmp; //majd nextelunk.
    }

    return l;
}

bool betaMaxker(Elem e)
{
    istringstream ss(e.sor);
    string tmp;
    ss>>tmp; //eldobom az elejerol a stringeket
    while(!ss.fail() && atoi(tmp.c_str())==0 && tmp != "0")
        ss>>tmp;

    bool l = false; //kerdes: van-e 10-es szam a korszamok kozott. pessz linker
    //most tmp-ben benne van az elso sorszam
    while(!ss.fail() && !l) //amig nem l és nem End (nem ert veget a sor)
    {
        l = tmp=="10"; //megnezzuk, igaz-e ra amit kerdezunk
        ss>>tmp; //majd beolvassuk a nekunk most nem kello koridot
        ss>>tmp; //majd nextelunk.
    }

    return l;
}

string tizedikkor(Elem e)
{
    istringstream ss(e.sor);
    string tmp;
    ss>>tmp; //eldobom az elejerol a stringeket
    while(!ss.fail() && atoi(tmp.c_str())==0 && tmp != "0")
        ss>>tmp;

    //most tmp-ben az elso szam van
    //kerdes: mi a tizeshez tartozo ertek. kivalasztas (mert csak akkor hivjuk ezt meg, ha van tizes)
    while(!ss.fail() && tmp!="10") //amig nem l és nem teljesul a feltetel
    {
        ss>>tmp; //addig beolvassuk a nekunk most nem kello koridot
        ss>>tmp; //majd nextelunk.
    }

    //amikor megallt akkor tmp-ben van a 10, ami utana jon az a 10. kor ideje:
    ss>>tmp;
    return tmp;
}

string versenyzo(Elem e)
{
    istringstream ss(e.sor);
    string tmp1,tmp2,tmp3;
    ss>>tmp1; //elso szocska
    ss>>tmp2; //masodik szocska
    ss>>tmp3; //harmadik szocska
    string nev = tmp1;

    //ha nev egy elemu, most a 3-ban szam van. Ha nem, akkor legalabb ket elemu...
    while(atoi(tmp3.c_str())==0 && tmp3 != "0")
    {
        nev += (" " + tmp2);
        tmp1 = tmp2;
        tmp2 = tmp3;
        ss>>tmp3;
    }

    return nev;
}
