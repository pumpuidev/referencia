#include <iostream>

using namespace std;

int main()
{
    //1. dekl: spec be, ki
    string k;
    int e;
    const string kartyak[8] = {"also", "felso", "kiraly", "asz", "vii", "viii", "ix", "x"};
    const int ertekek[8] = {2,3,4,11,7,8,9,10};




    //2. beolvasás spec be
    //Ellenõrzés
    bool jo;
    do
    {
        cout << "Kartya = ";
        cin >> k;
        int i=0;
        while (i<=8-1 && kartyak[i] != k)
        {
            i = i + 1;
        }
        jo = i<=7;
        if (!jo)
        {
            cout << "Nem jo" << endl;
        }
    }
    while(!jo);



    //3. feld: alg



    int i = 0;
    while (kartyak[i] != k)
    {
        i = i+1;
    }
    e = ertekek[i];



    //4. kiiras: spec ki



    cout << "Ertek = " << e << endl;





    return 0;
}
