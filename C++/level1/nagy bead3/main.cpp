//Prorok Ernest
//FILSPA
//14. feladat
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXN = 10000;

void beKonz(int &n, int meres[]);
void beFile(char * filename, int &n, int meres[]);

int getArvizKat(const int meres);

int felA(const int n, const int meres[]);
void felB(const int n, const int meres[], int megB[]);
int felC(const int n, const int meres[]);
void felD(const int n, const int meres[], int megD[]);

int main(int argc, char * argv[])
{
    int n;
    int meres[MAXN];

    int megA;
    int megB[MAXN] = {0};
    int megC;
    int megD[MAXN] = {0};
    cout<<"Kerem az N meresi pontot es az ertekeit! "<<endl;

    if (argc > 1) beFile(argv[1], n, meres);
    else beKonz(n, meres);

    megA = felA(n, meres);
    felB(n, meres, megB);
    megC = felC(n, meres);
    felD(n, meres, megD);

    cout <<"arvizek K darabszama: "<< megA << endl;
    cout<<"K arviznek kezdete es vege: ";
    for (int i = 0; i < n; i++) {
        if (megB[i] != 0) cout << megB[i] << " ";
    } cout << endl;

    cout <<"arvizvedelmi keszultseg csokkenest tartalmazo arvizek M szama: "<< megC << endl;
    cout <<"M arviz kezdete es vege: ";
    for (int i = 0; i < n; i++) {
        if (megD[i] != 0) cout << megD[i] << " ";
    }

    return 0;
}

void beKonz(int &n, int meres[]) {
    bool hiba;

    do {
        cin >> n;

        hiba = n < 0 || n > MAXN || cin.fail();

        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(hiba);

    for (int i = 0; i < n; i++) {
        do {
            cin >> meres[i];

            hiba = meres[i] < 0 || meres[i] > 3000 || cin.fail();

            if (hiba) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while(hiba);
    }
}

void beFile(char * filename, int &n, int meres[]) {
    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        file >> n;

        for (int i = 0; i < n; i++) {
            file >> meres[i];
        }

        file.close();
    } else exit(1);
}

int getArvizKat(const int meres) {

    if (meres <= 800) return 0;
    else if (meres < 900) return 1;
    else if (meres < 1000) return 2;

    return 3;
}


int felA(const int n, const int meres[]) {
    int result = 0;
    int j;
    int db = 0;

    for (int i = 0; i < n; i++) {
        j = i;

        while (meres[j] > 800 && j < n) {
            if (meres[i] > 800) db++;

            j++;
        }

        i = j;

        if (db > 0) {
            result++;
            db = 0;
        }
    }

    return result;
}

void felB(const int n, const int meres[], int megB[]) {
    int j;
    int k = 0;
    int db = 0;

    for (int i = 0; i < n; i++) {
        j = i;

        if (meres[i] > 800) {
            megB[k] = i+1;
            k++;
        }

        while (meres[j] > 800 && j < n) {
            if (meres[i] > 800) db++;

            j++;
        }

        i = j;

        if (db > 0) {
            megB[k] = i;
            k++;
            db = 0;
        }
    }
}

int felC(const int n, const int meres[]) {
    int result = 0;
    int i = 0;
    bool kategValtas = false;

    while (i < n) {
        while (i < n && meres[i] <= 800) {
            kategValtas = false;
            i++;
        }

        while (i < n && meres[i] > 800) {
            if (!kategValtas && getArvizKat(meres[i]) < getArvizKat(meres[i-1])) kategValtas = true;

            i++;
        }

        if (kategValtas) result++;
    }

    return result;
}

void felD(const int n, const int meres[], int megD[]) {
    int i = 0;
    int k = 0;
    int kezdInd;
    bool kategValtas = false;

    while (i < n) {
        while (i < n && meres[i] <= 800) {
            kategValtas = false;
            i++;
        }

        kezdInd = i+1;

        while (i < n && meres[i] > 800) {


            if (!kategValtas && getArvizKat(meres[i]) < getArvizKat(meres[i-1])) {
                kategValtas = true;
            }

            i++;
        }

        if (kategValtas) {
            megD[k] = kezdInd;
            k++;

            megD[k] = i;
            k++;
        }
    }
}
