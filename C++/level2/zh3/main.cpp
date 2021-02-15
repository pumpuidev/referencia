#include <iostream>
#include "enor.h"

using namespace std;

int hanydarab(Elem e);

int main()
{
    /*
    ELLENORZO KIIRAS
    Enor t;
    for(t.First();!t.End();t.Next())
    {
        cout<<t.Current().nev<<" "<<t.Current().csapat<<" [";

        for(int i=0;i<t.Current().koridok.size();++i)
        {
            cout<<"("<<t.Current().koridok[i].sorszam<<", "<<t.Current().koridok[i].ido<<")";
            if(i<t.Current().koridok.size() -1)
                cout<<", ";
        }

        cout<<"]"<<endl;
    }*/

    //kinek volt a legtobb masfel percnel jobb korideje
    //maxkiv
    //f: hany darab masfel percnel rovidebb kore volt
    //elem: maga a t.Current, es majd ennek lekerjuk  nevet

    Enor t;
    t.First();
    Elem elem = t.Current();
    int maxdarab = hanydarab(t.Current());
    for(t.Next();!t.End();t.Next())
    {
        if(maxdarab < hanydarab(t.Current()))
        {
            maxdarab = hanydarab(t.Current());
            elem = t.Current();
        }
    }

    cout<<"A legtobb masfel percnel jobb korideje "<<elem.nev<<"-nak/nek vaut."<<endl;

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
