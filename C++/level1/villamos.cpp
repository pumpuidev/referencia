
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    int N;
    string fajlnev;                   //fájlból olvasunk be
    ifstream f;                       //fájlváltozó definiálása
    struct TVili{                     //Adatszerkezet definiálása
        int sor;
        int tav;
        int erk;
        int ind;
    };
    //Beolvasás
    do {
        cout << "fajlnev (kiterjesztessel egyutt): ";
        cin >> fajlnev;
        f.open (fajlnev.c_str());
        if (f.fail()) {
            cout << "hiba a fajl megnyitasa kozben!"<<endl;
        }
    } while (f.fail());
    //Beolvasás vége
    f >> N;
    TVili Vili[N];                    //Adatszerkezet deklarálása

    char c;                           //Állomás sorszáma miatti pont bolvasására
    for (int i=0;i<N;i++) {
        f >> Vili[i].sor;
        f >> c;
        f >> Vili[i].tav;
        f >> Vili[i].erk;
        if (i==N-1) {
                Vili[i].ind=0;
        } else {f >> Vili[i].ind;};
    }
    f.close();

    //C részfeladat
    cout << "C: Az utvonal hossza: ";
    int hossz=0;
    for (int i=0;i<N;i++) {
        hossz +=Vili[i].tav;
    }
    cout <<hossz<<endl;

    //UU részfeladat
    cout << "UU: 1000 meternel hosszabb allomasszakaszok: "<<endl;
    int db=0;
    if (N!=1) {
        for (int i=0;i<N;i++) {
            if (Vili[i].tav >= 1000) {
                cout << "Az "<<Vili[i-1].sor<<". es "<<Vili[i].sor<<". allomas kozott"<<endl;
                db++;
            }
        }
    }
    if (db==0) {
    cout << "Nincs ilyen szakasz"<<endl;
    }

    //CCC részfeladat
    cout << "CCC: Legkozelebbi megallo: "<<endl;
    int j=0;
    if (N!=1) {
        for (int i=0;i<N;i++) {
            j=i+1;
            while ((j<(N-1)) and (Vili[j].erk==Vili[j].ind)) {
                j++;
            }
            if (i<(N-1)) {
            cout << Vili[i].sor<<". allomas: "<<Vili[j].sor<<". allomas"<<endl;
            }
        }
    } else {
    cout << "Nincs tobb megallo"<<endl;
    }

    return 0;
}
