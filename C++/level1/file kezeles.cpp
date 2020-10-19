#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXN=100;


void getStringFromFile(string filename, string &str) {
//fájl megnyitása


//fájl olvasása


//fájl lezárása


}

void getArrayFromFileN(string filename, int &N, string arr[MAXN]) {
//fájl megnyitása


//fájl olvasása


//fájl lezárása


}

void getArrayFromFile(string filename, int &N, string arr[MAXN]) {
//fájl megnyitása


//fájl olvasása


//fájl lezárása


}


void getArraysFromFileNM(string filename, int &N, int &M, string arr[MAXN][MAXN]) {
//fájl megnyitása


//fájl olvasása


//fájl lezárása


}


void getArraysFromFile(string filename, int &N, int &M, string arr[MAXN][MAXN]) {
//fájl megnyitása


//fájl olvasása


//fájl lezárása


}



int main()
{

    cout << "FAJLKEZELES" << endl << endl;

//String olvasása
    cout << "getStringFromFile: " <<endl;
    string s;

    getStringFromFile("f_str_in.txt",s);

    cout << s << endl << endl;


//1D Tömb olvasása 1
    cout << "getArrayFromFileN: " << endl;
    int N;
    string tomb[MAXN];

    getArrayFromFileN("f_arrayN_in.txt",N,tomb);

    cout << N << endl;
    for (int i=0;i<N;i++) {
        cout << tomb[i] << "; ";
    }
    cout << endl << endl;

//1D Tömb olvasása 2
    cout << "getArrayFromFile: " << endl;
    int N2;
    string tomb2[MAXN];

    getArrayFromFile("f_array_in.txt",N2,tomb2);

    cout << N2 << endl;
    for (int i=0;i<N2;i++) {
        cout << tomb2[i] << "; ";
    }
    cout << endl << endl;

//2D Tömb olvasása 1
    cout << "getArraysFromFileNM: " << endl;
    int S;
    int O;
    string tomb3[MAXN][MAXN];

    getArraysFromFileNM("f_arraysNM_in.txt",S,O,tomb3);

    cout << S << endl;
    cout << O << endl;
    for (int i=0;i<S;i++) {
        for (int j=0;j<O;j++) {
            cout << tomb3[i][j] << "; ";
        }
        cout << endl;
    }
    cout << endl;


//2D Tömb olvasása 2
    cout << "getArraysFromFile: " << endl;
    int S2;
    int O2;
    string tomb4[MAXN][MAXN];

    getArraysFromFile("f_arrays_in.txt",S2,O2,tomb4);

    cout << S2 << endl;
    cout << O2 << endl;
    for (int i=0;i<S2;i++) {
        for (int j=0;j<O2;j++) {
            cout << tomb4[i][j] << "; ";
        }
        cout << endl;
    }
    cout << endl;

    string vege;
    cout << endl << endl << " --- Vege --- ";
    getline(cin,vege);

    return 0;
}
