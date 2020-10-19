#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 100;

void beolvas(int &n, string szavak[MAXN]);

void atlagszamitas(const int n, const string szavak[MAXN],
                   double &atlag) {
    //3. feld
    atlag = 0;
    for (int i = 0; i<=n-1; i++) {
        atlag = atlag + szavak[i].length();
    }
    atlag = atlag / n;
}

void kiiras(const double er) {
    //4. kiiras
    cout << "A szavak hosszanak atlaga: "
         << er << endl;
}

int main()
{
    //1. dekl
    int n;
    string szavak[MAXN];
    double atlag;

    beolvas(n, szavak);  //spec be
    atlagszamitas(n, szavak, atlag);  //be --> ki
    kiiras(atlag);  //spec ki

    return 0;
}

void beolvas(int &n, string szavak[MAXN]) {
    ifstream be("be.txt");
    //2. beolv
    bool rossz;
    do {
        cout << "Szavak szama: ";
        be >> n;
        rossz = !(n>0);
        if (rossz) {
            cout << "Rossz adat!" << endl;
        }
    } while (rossz);
    for (int i = 0; i <= n-1; i++) {
        do {
            cout << i+1 << ". szo: ";
            be >> szavak[i];
            rossz = !(szavak[i]!="");
            if (rossz) {
                cout << "Rossz adat" << endl;
            }
        } while(rossz);
    }
    be.close();
}
