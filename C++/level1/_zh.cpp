//Feladat: adott egy tömb, állapítsuk meg, hogy minden eleme tökéletes szám-e!
//tökéletes szám: önmagán kkívüli osztók összege egyenlő a számmal. pl. 6, osztói 1, 2, 3  és 1+2+3=6
//ELDÖNTÉS TÉTEL

#include <iostream>
#include <math.h> //sqrt

using namespace std;

const int MaxN=1000; // tömb  max merete

int main()
{
    int N; //megadott mérete a tömbnek
    int T[MaxN];
    bool Minden, rossz; //eldöntéshet, beolvasáshoz
    do
    {
        cout << "Add meg a meretet: ";
        cin >> N;


        rossz= cin.fail() or N<0;
        if (rossz)
        {
            cout <<"Hibas bemenet. Nemnegativ szamot adjon meg."<< endl;
            cin.clear();
            cin.ignore();
        }
    }
    while(rossz);

    for (int i=0; i<N; i++)
    {
        do
        {
            cout << "A tomb "<< i+1<< ". eleme: ";
            cin>> T[i];

            rossz= cin.fail() or T[i]<0;
            if (rossz)
            {
                cout <<"Hibas bemenet. Nemnegativ szamot adjon meg."<< endl;
                cin.clear();
                cin.ignore();
            }

        }
        while(rossz);
    }

//feldolgozás:
    int osszeg=0;
    int i=0;
    Minden=true;
    while (i<N and Minden) //elég addig menni, amíg egy ellenpéldát találunk
    {
        if (T[i]==0)
            osszeg=1;
        else
            osszeg=0;
        for (int j=1; j<= sqrt(T[i]); j++) // a szám gyökéig vizsgáljuk az osztókat
        {
            if (T[i]%j==0) //ha osztó
            {
                if (j!=T[i]/j)  //ha olyan osztó, aminek a négyzete nem maga  a szám 
                    osszeg=osszeg+j+T[i]/j;
                else //ha  a négyzete maga  a szám (ha ugyanúgy működne, mint a másik ág, a négyzetgyököt kétszer számolnánk osztónak)
                    osszeg=osszeg+j;
            }

        }
        Minden=osszeg/2.0==T[i]; //minden osztót összeadtunk, ebből levesszük magát a számot
                                //2.0 -> a simán 2 int típus lenne, a 2.0-val cast-oljuk (konverzió) double-é, ez csak az 1 miatt kell, mert ha 
                                //a bemenet 1, megpróbálja elosztani kettővel, int esetén 0.5 helyett 1 maradna, és azt mondaná, hogy tökéletes szám
        i++;
    }

    if (Minden) cout << "Minden szam tokeletes volt!";
    else cout << "\"Nem minden szam tokeletes.";
    return 0;
}
