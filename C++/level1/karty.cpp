#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    /*
    string kartyak [8] = {"also","felso","kiraly","asz","hetes","nyolcas","kilences","tizes"};
    cout << kartyak [5] ; // a t�mb i edik elemel�t adjuk meg :t�mb [i]
    int ertekek [8] = {2,3,4,11,7,8,9,10};
    string kartya;
    cout << "Milyen lapod van?";
    cin >> kartya ;
    int cv =0;
    while (kartyak[cv]!=kartya)
    {
        cv++;
    }
    cout <<"a kartya  erteke:" << ertekek [cv] << endl;

    int lapokszama;
    cout << "lapok szama: ";
    cin >> lapokszama;
    int pontszam=0;
    for (int i=1; i<=lapokszama; i++)
    {
        cout << i << " lap: ";
        cin >> kartya;
        //KARTYA ertekenek megkers�se
        cv =0;
        while (kartyak[cv]!=kartya)
            {
                cv++;
            }
            //n�velj�k a pontszam �rt�k�t a kartya ertekelvel
            pontszam+=ertekek[cv];

    }
    cout <<"ossz pontszam: " << pontszam ;
    return 0;
    */
    string tizesek [10] = {"","tizen","huszon","harminc","negyven","�tven","hatvan","hetven","nyolcavan","kilenceven"};
    string eggyesek [10] = {"","egy","ketto","h�rom","n�gy","�t","hat","h�t","nyolc","kilenc"};
    int szam, tizedes, eggyes ;
    string szam_szoveggel;
    cout << "adj meg egy szamot 1 es 99 kozott!" ;
    cin >> szam;
    if (szam == 10)
    {
        cout << "tiz" << endl;
    }
    else if (szam == 20)
    {
        cout << "husz" << endl;
    }
    else
    {
        tizedes = szam / 10;
        eggyes = szam % 10;
        szam_szoveggel = tizesek[tizedes]+eggyesek[eggyes];
        cout << szam_szoveggel << endl;
    }


}
