/*
Prorok Ernest
filspa
ernest.prorok@gmail.com
„ProgAlap beadandó feladatok” téma: Árvízmentes szakaszok teljes hossza
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int MAXN = 10000;

int menu();

void beFile(int &, int []);
void beKonz(int &, int []);

int elso(const int, const int []);
void masodik(const int, const int [], int []);
void harmadik(const int, const int [], int []);
int negyedik(const int, const int []);

int main() {
    int n, choice;
    int szakasz[MAXN];
    int a, d;
    int b[MAXN] = {0};
    int c[MAXN] = {0};


    choice = menu();
    switch(choice) {
        case 1:
            beFile(n, szakasz);
            break;

        case 2:
           beKonz(n, szakasz);
           break;
   }

    a = elso(n, szakasz);
    masodik(n, szakasz, b);
    harmadik(n, szakasz, c);
    d = negyedik(n, c);

    cout << a << endl;
    if (a != 0) {
        for (int i = 0; i < n; ++i) {
            if (b[i] != 0) cout << b[i] << " ";
        } cout << endl;
        for (int i = 0; i < n; ++i) {
            if (c[i] != 0) cout << c[i] << " ";
        } cout << endl;
        cout << d;
    }

    return 0;
}

int menu() {
    int result;

    cerr << "VALASSZ A BEMENETEK KOZOTT!\n";
    cerr << "FAJL (1) VAGY KONZOL (2): ";

    do {
        cin >> result;

        if (result > 2 || result < 1 || cin.fail()) {
            cerr << "HIBAS MENUPONT VALASZTAS! A KET OPCIO KOZUL VALASSZ!\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(result > 2 || result < 1 || cin.fail());

    return result;
}

void beFile(int &n, int szakasz[]) {
    string fname;
    ifstream infile;

    cerr << "ADD MEG A BEMENETI FAJLT: ";
    do {
        cin >> fname;

        infile.clear();
        infile.open(fname.c_str());

        if (infile.fail()) cerr << "HIBAS BEMENETI FAJL, A MEGADOTT FAJL NEM TALALHATO.\n";
    } while(infile.fail());

    infile >> n;
    for (int i = 0; i < n; ++i) {
        infile >> szakasz[i];
    }
}

void beKonz(int &n, int szakasz[]) {
    cerr << "A BEMENETI ADATOK SZAMA: ";
    do {
        cin >> n;

        if (n > MAXN || n < 0 || cin.fail()) {
            cerr << "HIBAS BEMENETI ADAT (0 <= N <= MAXN)\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(n > MAXN || n < 0 || cin.fail());

    for (int i = 0; i < n; ++i) {
        cerr << "ADJA MEG A(Z) " << i+1 << ". BEMENETI ADATOT: ";

        do {
            cin >> szakasz[i];

            if (szakasz[i] > 3000 || szakasz[i] < 0 || cin.fail()) {
                cerr << "HIBAS BEMENETI ADAT! A VIZALLAS 0 ES 3000 KOZE KELL ESSEN!\n";

                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while(szakasz[i] > 3000 || szakasz[i] < 0 || cin.fail());
    }
}

int elso (const int n, const int szakasz[]) {
    int result = 0;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        if (szakasz[i] <= 800) ++j;
        else {
            if (j != 0) ++result;

            j = 0;
        }
    }

    if (j != 0) {
                cerr << szakasz[n];
                ++result;
    }

    return result;
}

void masodik(const int n, const int szakasz[], int b[]) {
    int j = 0;
    int k = 0;

    for (int i = 0; i < n; ++i) {
        if (szakasz[i] <= 800) {
            if (j == 0) {
                b[k] = i+1;
                ++k;
            }

            ++j;
        } else {
            if (j != 0) {
                b[k] = i;
                ++k;
            }

            j = 0;
        }
    }

    if (j != 0) b[k] = n;
}

void harmadik(const int n, const int szakasz[], int c[]) {
    int j = 0;
    int k = 0;

    for (int i = 0; i < n; ++i) {
        if (szakasz[i] <= 800) ++j;
        else {
            if (j != 0) {
                c[k] = j;
                ++k;
            }

            j = 0;
        }
    }

    if (j != 0) c[k] = j;
}

int negyedik(const int n, const int c[]) {
    int result = 0;

    int i = 0;
    while (c[i] != 0) {
        result += c[i];
        ++i;
    }

    return result;
}
