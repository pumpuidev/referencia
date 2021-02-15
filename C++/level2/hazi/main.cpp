
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "naplo.h"
#include "read.h"

using namespace std;

//Feladat: 	A fõprogram gondoskodik a beolvasás, a kiértékelés, kiíratás részek aktivizálásáról.

int main(int argc, char *argv[])
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    // Beolvasás
    int s = 0;
    string fajlnev;
    if (argc<=1) {
        cout << "Valassza ki az adatbevitel modjat!\n";
        cout << "1 - adatok beolvasasa fajlbol\n";
        cout << "2 - adatok beolvasasa billentyuzetrol\n";
        cout << "3 - kilepes\n";
        s = read_int("Adatbevitel modja: ", "1, 2 vagy 3 lehet", egykettoharom);
    }
    switch (s) {
        case 0:
            if(argc>1) {
            fajlnev = argv[1];
            fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            }
            else exit(0);
            break;

        case 1:
            cout << "Add meg a fajl nevet: ";
            cin >> fajlnev;
            fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            break;

        case 2:
            n = read_int("Hany tanulo van? ", "Termeszetes szamot kerek!", nat);
            cout << "Adja meg a tanulok neveit:" << endl;
            neveket_olvas(n, "tanulo", tanulo);
            cout << endl;

            m = read_int("Hany tantargy van? ","Termeszetes szamot kerek!", nat);
            cout << "Adja meg a tantargyakat:"<< endl;
            neveket_olvas(m, "tantargy", targy);
            cout << endl;

            cout << "Adja meg az osztalyzatokat!"<< endl;
            jegyeket_olvas(tanulo, targy, naplo);
            cout << endl;
            break;

        default:
            exit(0);
    }

    // Kiértékelés
    if (mindenkinek_ket_otos(naplo)) {
        cout << "Mindenkinek legalabb ket otose van az osztalyban!";
    }
    else {
        cout << "Van olyan az osztalyban, akinek nincs ket otose!";
    }

    cout<<endl;
    return 0;
}
