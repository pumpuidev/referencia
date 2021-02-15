#include <iostream>
#include "enor.h"

using namespace std;

int hanydarab(Elem e);
bool voltE10Kor(Elem e);
string tizedikKorideje(Elem e);

int main()
{
    //kinek volt a legtobb masfel percnel jobb korideje
    //maxkiv
    //f: hany darab masfel percnel rovidebb kore volt
    //elem: maga a t.Current, es majd ennek lekerjuk  nevet

    //ki futotta a legjobb koridot a 10-ben
    //feltmaxker
    //f: a tizedikhez tartozo korideje
    //beta:van-e tizedik kore nekijjje
    //elem: maga a t.current, majd ennek lekerjuk a nevet...
    //mivel van egy maxkivunk IS, ezert a feltmaxker joooo hosszu lesz: kulon kenytelenek vagyunk megnezni az elso elemre is a ciklus elott ugyanazt amit a ciklusban is a tobbire.

    Enor t;
    Elem elemTizedik;
    string maxidoTizedik;
    bool volteTizedik = false;
    t.First();
    if(voltE10Kor(t.Current()))
    {
        volteTizedik = true;
        maxidoTizedik = tizedikKorideje(t.Current());
        elemTizedik = t.Current();
    }
    Elem elemMasfel = t.Current();
    int maxdarabMasfel = hanydarab(t.Current());
    for(t.Next();!t.End();t.Next())
    {
        if(maxdarabMasfel < hanydarab(t.Current()))
        {
            maxdarabMasfel = hanydarab(t.Current());
            elemMasfel = t.Current();
        }

        if(voltE10Kor(t.Current()))
        {
            if(volteTizedik)
            {
                if(maxidoTizedik>tizedikKorideje(t.Current()))
                {
                    maxidoTizedik = tizedikKorideje(t.Current());
                    elemTizedik = t.Current();
                }
            }
            else
            {
                volteTizedik = true;
                maxidoTizedik = tizedikKorideje(t.Current());
                elemTizedik = t.Current();
            }
        }
    }

    cout<<"A legtobb masfel percnel jobb korideje "<<elemMasfel.nev<<"-nak/nek vaut."<<endl;
    if(volteTizedik)
        cout<<"A legjobb 10. koros ideje "<<elemTizedik.nev<<"-nak/-nek vot."<<endl;
    else
        cout<<"Tizedik kore biza senkinek se volt."<<endl;

    return 0;
}

int hanydarab(Elem e)
{
    //megszamlaljuk, mennyi olyan van ami teljesiti a feltetelt.
    //beta: a jelenlegi korido kisebb mint masfel percz
    int c=0;
    for(size_t i=0;i<e.koridok.size();++i)
        if(e.koridok[i].ido<"01:30:000")
            ++c;
    return c;
}

bool voltE10Kor(Elem e)
{
    bool l = false;
    for(size_t i=0;i<e.koridok.size() && !l;++i)
        l = e.koridok[i].sorszam == 10;

    return l;
}

string tizedikKorideje(Elem e)
{
    //kivalasztassal megnezem a 10-et, merugye ezt a fv-t csak akkor hivom meg ha van 10.
    size_t i;
    for(i=0;e.koridok[i].sorszam !=10;++i);

    return e.koridok[i].ido;
}
