#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("f.txt");


    //maxkiv minimumra
    //felt maxker minimumra
    bool l = false;
    double maxKoridoNovekvo;
    Elem maxKoridoNovekvoElem;
    t.First();
    if(t.Current().novekvo)
    {
        l = true;
        maxKoridoNovekvo = t.Current().atlagosIdo;
        maxKoridoNovekvoElem = t.Current();
    }
    double maxKorido = t.Current().atlagosIdo;
    Elem maxKoridoElem = t.Current();
    for(t.Next();!t.End();t.Next())
    {
        if(maxKorido>t.Current().atlagosIdo)
        {
            maxKorido = t.Current().atlagosIdo;
            maxKoridoElem = t.Current();
        }

        if(t.Current().novekvo)
        {
            if(l)
            {
                if(t.Current().atlagosIdo < maxKoridoNovekvo)
                {
                    maxKoridoNovekvo = t.Current().atlagosIdo;
                    maxKoridoNovekvoElem = t.Current();
                }
            }
            else
            {
                l = true;
                maxKoridoNovekvo = t.Current().atlagosIdo;
                maxKoridoNovekvoElem = t.Current();
            }
        }
    }

    cout<<"A legjobb atlagos korideje "<<maxKoridoElem.nev<<"-nak/-nek volt."<<endl;
    if(l)
        cout<<"Valamint "<<maxKoridoNovekvoElem.nev<<"-nak/-nek a javulok kozott."<<endl;
    else
        cout<<"Javulok meg nem voltak :("<<endl;

    return 0;
}
