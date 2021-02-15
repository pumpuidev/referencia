#include <iostream>
#include<sstream>
#include "enor.h"

using namespace std;

bool beta(Elem e);

int main()
{
    //szamlalas felsorolora
    Enor t;
    int c = 0;
    for(t.First();!t.End();t.Next())
        if(beta(t.Current()))
            ++c;

    cout<<"Ennyinek volt masfelnel jobb a korideje: "<<c<<endl;
    return 0;
}

bool beta(Elem e) //az e-ben van egy szoveg ami a versenyzorol minden adatot tartalmaz (e.sor)
{
    istringstream ss(e.sor); //ezt feldolgozzuk
    string tmp;
    ss>>tmp; //beolvassuk a nevet...
    ss>>tmp; //a csapatot... mert ezek nem fontosak

    bool l = false; //kerdes: van-e masfelnel gyorsabb? ez egy (pessz) linker...
    ss>>tmp;//ez a linker az "ss"-t jarja be az elso korsorszamtol kezdodoen. Ennek ez a "first"-je: be kell olvasnunk a korsorszamot
    while(!ss.fail() && !l) //amig nem l és nem End (nem ert veget a sor)
    {
        ss>>tmp; //addig beolvassuk az akt koridot
        l = tmp<"01:30:000"; //megnezzuk, igaz-e ra amit kerdezunk
        ss>>tmp; //majd nextelunk.
    }

    //ez amolyan feloldalasan halad: elobb beolvassa az akt. kor sorszamat, majd ha ez sikerult akkor olvassa csak be a ciklusmagban mar az idot
    //oka, hogy muszaj elore olvasnunk mert csak akkor derul ki, ha vege van a fajlnak
    //(abbol hogy nem sikerult az olvasas)

    return l;
}
