
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
class Allomas {
    public:
        string nev;
        int le, fel, sor, mostB;
        static int most;
        Allomas (int x, string s) {
            sor = x;
            int db = 0;
            string seged = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ';') {
                    db++;
                    switch(db) {
                        case 1: nev = seged;
                            break;
                        case 2: le = atoi(seged.c_str());
                            break;
                    }
                    seged = "";
                }
                else seged = seged + s[i];
                if (i == s.length() - 1) fel = atoi(seged.c_str());

            }
            if (sor == 1) most = fel;
            else {
                most = most - le + fel;
            }
            mostB = most;
        }
        int getMost () {
            return most;
        }
        int getMostB () {
            return mostB;
        }
        string getString () {
            stringstream ss;
            ss << sor << ". allomas, " << nev << ": " << le << " leszallo, " << fel << " felszallo, " << most << " utas van jelenleg";
            return ss.str();
        }
        string getKulonbseg () {
            int kul = mostB * 100 - 1000;
            stringstream ss;
            if (mostB == 0) {
                ss << "nem kozledik (ures)";
            }
            else {
                if (kul < 0) ss << abs(kul) << " Ft a veszteseg";
                else if (kul == 0) ss << "nincs rajta se nyereseg, se veszteseg.";
                else ss << kul << " Ft a nyereseg";
            }
            return ss.str();
        }
        int getKulonbsegB () {
            int kul = mostB * 100 - 1000;
            if (mostB == 0) return 0;
            else return kul;
        }
        string getNev () {
            return nev;
        }
};
void fajlFel ();
void billBe ();
int Allomas::most = 0;
vector <Allomas> v;
int main() {
    while (true) {
        cout << "MENU: A kovetkezo opciok kozul valaszthat.\n'1' - Felolvasas fajlbol\n'2' - Beolvasas klaviaturarol\n'x' - Kilepes\nKerem a valasztast: ";
        string s;
        cin >> s;
        cout << endl;
        if (s == "1") fajlFel();
        else if (s == "2") billBe();
        else if (s == "x") {
            cout << "A program mukodese leall.\n";
            break;
        }
        else {
            cout << "HIBA! A megadott lehetosegek kozul valaszon!\n\n";
        }
    }
    return 0;
}
bool pozitivIntE (string s) {
    bool t1 [s.length()];
    const char t2 [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < s.length(); i++) {
        t1[i] = false;
        for (int j = 0; j < 10; j++) {
            if (s[i] == t2[j]) t1[i] = true;
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (t1[i] == false) return false;
    }
    return true;
}
bool joE (string s, int index, int n) {
    string t [3];
    string seged = "";
    int db = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ';') {
            db++;
            switch(db) {
                case 1: t[0] = seged;
                    break;
                case 2: t[1] = seged;
                    break;
            }
            seged = "";
        }
        else seged = seged + s[i];
        if (i == s.length() - 1) t[2] = seged;
    }
    int le = atoi(t[1].c_str()), fel = atoi(t[2].c_str());
    bool allitas = true;
    if (!(db == 2)) allitas = false;
    if (t[0] == "") allitas = false;
    if (index != 1) {
        Allomas elozo = (Allomas) v.at(index - 2);
        if (elozo.getMost() < le) allitas = false;
    }
    if (index == 1 && le != 0) allitas = false;
    if (index == n && fel != 0) allitas = false;
    if (!pozitivIntE(t[1])) allitas = false;
    if (!pozitivIntE(t[2])) allitas = false;
    if (index == n) {
        Allomas elozo = (Allomas) v.at(index - 2);
        if (elozo.getMost() != le) allitas = false;
    }
    return allitas;
}
void osszegzes () {
    cout << "\nVonat/XX FELADAT:\n\n";
    int szum = 0, db = 0;
    for (int i = 1; i < v.size(); i++) {
        Allomas elozo = (Allomas) v.at(i - 1);
        Allomas mostani = (Allomas) v.at(i);
        cout << elozo.getNev() << " - " << mostani.getNev() << ": " << elozo.getKulonbseg() << endl;
        szum += elozo.getKulonbsegB();
        if (elozo.getMostB() == 0) db++;
    }
    cout << "\n" << (v.size() - 1 - db) << " helyi vonat indult, ";
    if (szum < 0) cout << abs(szum) << " Ft a tarsasag vesztesege.";
    else if (szum == 0) cout << "nem volt rajta se nyereseg, se veszteseg.";
    else cout << szum << " Ft a tarsasag nyeresege.";
    cout << "\n" << endl;
}
int sorokSzama (string s) {
    string sor, fajlNev;
    ifstream fajl(s.c_str());
    int n = 0;
    while (getline (fajl,sor)) {
            n++;
    }
    fajl.close();
    return n;
}
void fajlFel () {
    v.clear();
    bool jo = true;
    string sor, fajlNev;
    cout << "Kerem a fajl nevet: "; cin >> fajlNev;
    cout << endl;
    ifstream fajl (fajlNev.c_str());
    if (fajl.is_open()) {
        int index = 0;
        while (getline (fajl,sor)) {
            index++;
            if (joE(sor,index,sorokSzama(fajlNev)) == false) {
                jo = false;
                break;
            }
            Allomas x (index, sor);
            v.push_back(x);
        }
        fajl.close();
        if (jo) {
            cout << "\nA fajl felolvasasa sikeres!\n\n";
            for (int i = 0; i < v.size(); i++) {
                Allomas x = (Allomas) v.at(i);
                cout << x.getString() << endl;
            }
            osszegzes();
        }
        else cout << "A fajl felolvasasa sikertelen, a fajl adatai nem felelnek meg a szabalyoknak!\n\n";;
    }
    else cout << "A fajl felolvasasa sikertelen, ugyeljen a fajl nevere es kiterjesztesere!\n\n";
}
void billBe () {
    v.clear();
    int szam;
    while (true) {
        string seged;
        cout << "Kerem az allomasok szamat: "; cin >> seged;
        int seged2 = atoi(seged.c_str());
        if (seged2 >= 2) {
            szam = seged2;
            break;
        }
        cout << "HIBA! ";
    }
    cout << "\nFIGYELEM! A kovetkezo formaban adja meg az allomast: nev;leszallok;felszallok\n\n";
    for (int i = 1; i <= szam; i++) {
        bool exit = false;
        while (!exit) {
            string sor;
            cout << "Kerem a(z) " << i << ". allomast: "; cin >> sor;
            if (joE(sor, i, szam)) {
                Allomas x(i, sor);
                v.push_back(x);
                cout << "\nSikeresen hozzaadva a vectorhoz!\n" << "Jelenleg "<< x.getMostB() << " utas tartozkodik a vonaton." << "\n\n";
                exit = true;
            }
            else cout << "\nHIBA! A megadott szabvany szerint adja meg az allomast!\n\n";
        }
    }
    osszegzes();
}
