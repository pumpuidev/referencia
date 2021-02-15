#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    if(t.End())
    {
        cerr<<"Nem letezo file :("<<endl;
    }
    else
    {
        t.First();
        if(t.End())
        {
            cout<<"Nem lehet ures fajlban maximumot kivalasztani"<<endl;
        }
        else
        {
          //ellenorzes:
//          cout<<t.Current().nev<<" "<<t.Current().chip<<" "<<t.Current().sikeres<<" "<<t.Current().osszpont<<endl;

            if(t.Current().sikeres) //osszegzes (kiiras) az elso elemre
                cout<<t.Current().nev<<" "<<t.Current().chip<<endl;

            int max = t.Current().osszpont; //maxkiv inicializalasa
            Kutymuty legjobb = t.Current();

            for(t.Next();!t.End();t.Next())
            {
                Kutymuty k = t.Current();

                //ellenorzes:
//                cout<<k.nev<<" "<<k.chip<<" "<<k.sikeres<<" "<<k.osszpont<<endl;

                if(k.sikeres)    //osszegzes (kiiras) a tobbi elemre
                    cout<<k.nev<<" "<<k.chip<<endl;

                if(k.osszpont > max)    //maxkiv
                {
                    max = k.osszpont;
                    legjobb = k;
                }
            }
            cout<<"A legerosebb kutya: "<<legjobb.nev<<endl;
        }
    }

    return 0;
}
