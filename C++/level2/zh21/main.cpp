#include <iostream>
#include "enor.h"

using namespace std;


int main()
{
    Enor t("be.txt");
    if(t.End())
    {
        cerr<<"Hibas file."<<endl;
    }
    else
    {
        //osszegzesnek hazudott linker
        bool volt5 = false;

        //feltmaxker
        //beta ~ van utazasa (a felsorolban uresre allitottam a "legkorabbi"-t, ha nincs)
        //f ~ a legkorabbi utazas ideje - a "legkorabbi" adattag
        //(H,>) ~ (String,< (beturend))
        //max ~ min
        //elem ~ legkorabbiUtas
        //l ~ voltUtazas
        bool voltUtazas = false;
        string min;
        Utas legkorabbiUtas;
        for(t.First();!t.End();t.Next())
        {
            Utas u = t.Current();

            //kiiras
//            cout<<u.azonosito<<" "<<u.legkorabbi<<" "<<u.utazasok<<endl;

            //linkernek hazudott osszegzes
            volt5 = volt5 || u.utazasok >= 5;

            //feltmaxker
            if("" != u.legkorabbi)
            {
                if(voltUtazas)
                {
                    if(u.legkorabbi < min)
                    {
                        min = u.legkorabbi;
                        legkorabbiUtas = u;
                    }
                }
                else
                {
                    voltUtazas = true;
                    min = u.legkorabbi;
                    legkorabbiUtas = u;
                }
            }
        }
        if(voltUtazas)
            cout<<"A legkorabbi utas "<<legkorabbiUtas.azonosito<<" volt, ekkor: "<<min<<"."<<endl;
        else
            cout<<"Egyaltalan nem volt utazas"<<endl;

        if(volt5)
            cout<<"Volt olyan, aki legalabb 5-szor utazott"<<endl;
        else
            cout<<"Nem volt olyan, aki legalabb 5-szor utazott"<<endl;
    }

    return 0;
}
