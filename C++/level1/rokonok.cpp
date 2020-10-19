#include <iostream>
#include <stdlib.h>

using namespace std;

const int MaxN = 100;
const int MaxK = 100;

struct Kapcsolat {
    int szulo, gyerek, szulEv;
};

void beolvas(int& N, int& K, string nevek[], Kapcsolat kapcsolat[], int &aE, int& aK, int& Gy, int& D, int& E);

int felA(const int N, const int K, const string nevek[], Kapcsolat kapcsolat[], const int aE, const int aK);

int main()
{
    // N = EMBEREK SZ·MA K = KAPCSOLATOK SZ·MA
    int N, K;
    string nevek[MaxN];
    Kapcsolat kapcsolat[MaxK];
    int aE, aK, Gy, D, E;

    beolvas(N, K, nevek, kapcsolat, aE, aK, Gy, D, E);

    int megA = felA(N, K, nevek, kapcsolat, aE, aK);

    // A FELADAT KIÌR·SA
    if (megA != -1) cout << nevek[kapcsolat[megA].gyerek - 1] << endl;
    else cout << "NINCS ILYEN EMBER" << endl;

    // B FELADAT KIÌR·SA
    cout << endl;

    // C FELADAT KIÌR·SA
    cout << endl;

    // D FELADAT KIÌR·SA
    cout << endl;

    // E FELADAT KIÌR·SA
    cout << endl;

    return 0;
}

void beolvas(int& N, int& K, string nevek[], Kapcsolat kapcsolat[], int &aE, int& aK, int& Gy, int& D, int& E) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nevek[i];
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> kapcsolat[i].szulo >> kapcsolat[i].gyerek >> kapcsolat[i].szulEv;
    }

    cin >> aE >> aK >> Gy >> D >> E;
}

int felA(const int N, const int K, const string nevek[], Kapcsolat kapcsolat[], const int aE, const int aK) {
    int megoldas = -1;

    for (int i = 0; i < K; i++) {
        if (kapcsolat[i].szulEv >= aE && kapcsolat[i].szulEv <= aK) {
            megoldas = i;
            break;
        }
    }

    return megoldas;
}
