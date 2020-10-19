//Prorok Ernest, FILSPA, torzsek: H,P,TT
#include <iostream>
#include <fstream>  // fajl
#include <string>   // string, fajl beolvas, fajlnev
#include <stdlib.h> // ki
#include <stdio.h>  // ki

using namespace std;

const int MAXN = 100;   // max elem

// haboruk deklarasa
struct War {
    string ki, kivel;
    int mettol, meddig;
};
// void
void konzolBe(int& torzs, int& haboruk, string torzsek[MAXN], War war[MAXN]);
void konzolBeFile(int& torzs, int& haboruk, string torzsek[MAXN], War war[MAXN]);

void feladatH(const int haboruk, const War war[MAXN]);
void feladatP(const int haboruk, const int torzs, const string torzsek[MAXN], const War war[MAXN]);
void feladatTT(const int haboruk, const int torzs,  const string torzsek[MAXN], const War war[MAXN]);

int main() {
// 1. dekl
    int torzs;
    // hany torzs
    int haboruk;
    // hany haboru
    string torzsek[MAXN];
    // torzs
    War war[MAXN];
    // haboru

    int choice;
    // bekeres
    bool hiba;
// 2. beolv
    do {
        cout << "Amennyiben a beolvasast fajlbol szeretne elvegezni irjon 2-est & enter,"<<endl<<"mas esetben billentyuzetrol keri be az adatokat irjon 1-est & enter." << endl;
        cin >> choice;

        hiba = cin.fail() || choice > 2 || choice < 1;

        if (hiba) {
            cout << "Csak a megadott lehetosegek validok.";

            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (hiba);

    if (choice == 2) konzolBeFile(torzs, haboruk, torzsek, war);
    else konzolBe(torzs, haboruk, torzsek, war);

// 3. feladat
 // H
 feladatH(haboruk, war);
 // P
 feladatP(haboruk, torzs, torzsek, war);
 // TT
 feladatTT(haboruk, torzs, torzsek, war);
    return 0;
}

void konzolBe(int& torzs, int& haboruk, string torzsek[MAXN], War war[MAXN]) {
    bool hiba;

    do {
        cout << "Adja meg a torzsek szamat: ";
        cin >> torzs;

        hiba = torzs < 0 || cin.fail();

        if (hiba) {
            cout << "HIBA A BEOLVASASBAN: HELYTELEN ADAT!" << endl;

            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(hiba);

    for (int i = 0; i < torzs; i++) {
        cout << "Adja meg a(z) " << i+1 << ". torzs nevet: ";
        cin >> torzsek[i];
    }

    if (torzs > 1) {
        cout << endl << "Adja meg a haboruk szamat: ";
        cin >> haboruk;

        for (int i = 0; i < haboruk; i++) {
            cout << i+1 << ". haboru" << endl;

            cout << "Ki harcolt: ";
            cin >> war[i].ki;
            cout << "Kivel harcolt: ";
            cin >> war[i].kivel;

            do {
                cout << "Mikor kezdodott a haboru: ";
                cin >> war[i].mettol;

                hiba = war[i].mettol < 1600 || cin.fail();
                if (hiba) {
                    cout << "HIBA A BEOLVASASBAN: HELYTELEN ADAT!";

                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } while(hiba);

            cout << "Mikor ert veget a havoru: ";
            cin >> war[i].meddig;

            cout << endl;
        }
    }
}
void konzolBeFile(int& torzs, int& haboruk, string torzsek[MAXN], War war[MAXN]) {
    string pathTorzs, pathHaboru, fileTorzs, fileHaboru;

    cout << "Adja meg a torzsek nevet tartalmazo fajl nevet, kiterjesztes nelkul: ";
    cin >> fileTorzs;
    fileTorzs.append(".txt");

    cout << "Adja meg a haborukat tartalmazo fajl nevet, kiterjesztes nelkul: ";
    cin >> fileHaboru;
    fileHaboru.append(".txt");

    pathTorzs = pathHaboru = "src/";
    pathTorzs.append(fileTorzs);
    pathHaboru.append(fileHaboru);

    // torzs tomb feltoltese
    ifstream torzsIn(pathTorzs.c_str(), ios::in);
    if (torzsIn.is_open()) {
        torzs = 0; // elemek szama

        while(!(torzsIn.eof())) {
            torzsIn >> torzsek[torzs];
            torzs++;
        }

    torzsIn.close();
    } else {
        cout << "HIBA, NEM SIKERULT MEGNYITNI A FAJLT." << endl;
        exit(1);    // kilepes (ha a file nem valid)
    }

    // a haboruk feltoltese
    ifstream haboruIn(pathHaboru.c_str(), ios::in);
    if (haboruIn.is_open()) {
        haboruk = 0;    // elemek szama

        while(!(haboruIn.eof())) {
            haboruIn >> war[haboruk].ki;
            haboruIn >> war[haboruk].kivel;
            haboruIn >> war[haboruk].mettol;
            haboruIn >> war[haboruk].meddig;

            haboruk++;
        }

    haboruIn.close();
    } else {
        cout << "HIBA, NEM SIKERULT MEGNYITNI A FAJLT." << endl;
        exit(1);    // kilep (ha a file nem valid)
    }
}

void feladatH(const int haboruk, const War war[MAXN]) {
// 5 evnel hosszabb haboruk szama
    int warIndex = 0;
    int haboruMax = war[0].meddig - war[0].mettol;

    int darab = 0;

   for (int i = 0; i < haboruk; i++) {
        if (war[i].meddig - war[i].mettol > 5) {
            darab++;
        }
   }

    cout << darab <<" darab haboru tartott 5 evnel tovabb."<< endl;
}

void feladatP(const int haboruk, const int torzs, const string torzsek[MAXN], const War war[MAXN]) {
    int warSzazad[3] = {0};
    int fordulo = 1700;
    int _fordulo = fordulo - 100;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < torzs; j++) {
            for (int k = 0; k < haboruk; k++) {
                if (war[k].mettol < fordulo && war[k].mettol > _fordulo) {
                    if (war[k].ki == torzsek[j] || war[k].kivel == torzsek[j]) {
                        warSzazad[i]++;
                        break;
                    }
                }

                else if (war[k].mettol < fordulo && war[k].mettol >= (_fordulo + 100)) {
                    if (war[k].ki == torzsek[j] || war[k].kivel == torzsek[j]) {
                        warSzazad[i+1]++;
                        break;
                    }
                }
            }
        }

        fordulo += 100;
        _fordulo += 100;
    }

    for (int i = 0; i < 3; i++) {
        cout << warSzazad[i] <<" haboru volt a szazadban."<< endl;
    }

    cout << endl << endl;
}

void feladatTT(const int haboruk, const int torzs,  const string torzsek[MAXN], const War war[MAXN]) {

    // kereses es maxkival tetel
    int mennyivel[MAXN] = {0};

    // kereses tetel
    for (int i = 0; i < torzs; i++) {
        for (int j = 0; j < haboruk; j++) {
            if (torzsek[i] == war[j].ki || torzsek[i] == war[j].kivel) {
                mennyivel[i]++;

                if (j <= haboruk-1) {
                    for (int k = j+1; k < haboruk; k++) {
                        if ((war[j].ki == war[k].ki && war[j].kivel == war[k].kivel) || (war[j].kivel == war[k].ki && war[j].ki == war[k].kivel)) {
                            mennyivel[i]--;
                        }
                    }
                }
            }
        }
    }

    int melyik;    // legnagyobb elem

    // maxkival tetel
    for (int i = 0; i < torzs; i++) {
        if (mennyivel[i] == 1) {
            melyik = i;
        }
    }

    cout << torzsek[melyik] << " torzs pontosan 1. haboruzott." << endl;
}
