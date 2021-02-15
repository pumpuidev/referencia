#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("f.txt");

    t.First();
    double maxKorido = t.Current().atlagosIdo; //maxkiv minimumra
    Elem maxKoridoElem = t.Current();
    for(t.Next();!t.End();t.Next())
    {
        if(maxKorido>t.Current().atlagosIdo)
        {
            maxKorido = t.Current().atlagosIdo;
            maxKoridoElem = t.Current();
        }
    }

    cout<<"A legjobb atlagos korideje "<<maxKoridoElem.nev<<"-nak/-nek volt."<<endl;

    return 0;
}
