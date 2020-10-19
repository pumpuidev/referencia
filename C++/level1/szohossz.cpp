#include <iostream>
#include <fstream>

/*B: N e N
    Szavak e S^N
K: Atlag e R
E:  -
U: S + X[i] */

using namespace std;
 const int MAXN = 100;
void beolvas (int &n,string szavak[MAXN])
{
    ifstream be("be.txt");
    // 2. beolv
    bool rossz;
    do
    {
        cout << "N darab szobol all a mondat: ";
        be >> n;
        rossz = !(n>0);
        if (rossz)
        {
            cout << "Rossz adat!" << endl;
        }
    }
    while (rossz);



    for (int i=0; i<=n-1; i++)
    {
        do
        {
            cout << i+1 << ". szo : ";
            be >> szavak[i];



            rossz = !(szavak[i]!="");
            if (rossz)
            {
                cout << "Rossz adat!" << endl;
            }
        }
        while (rossz);
    }
    be.close();
}

 void atlagszamitas (const int n, const string szavak[MAXN], double &atlag){

     atlag =0;

    for (int i=0; i<=n-1; i++)
    {
        atlag= atlag+ szavak[i].length();
    }

    atlag= atlag/n;


 }

 void kiiras (const double atlag){
 // 4.kiiras
   cout << "atlag : " <<atlag << endl;
 }

int main()
{
    //1.dekl

    string szavak[MAXN];

    int n;
    double atlag;

    beolvas(n,szavak); //spec be
    atlagszamitas (n, szavak, atlag); // be >> ki
    kiiras (atlag); //spec ki

    return 0;
}
