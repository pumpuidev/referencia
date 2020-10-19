#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct Lakas {
    int ar, terulet;
};

const int MaxN = 100;

void beolvas(int& N, int& A, int& B, int& K, int& idealisAr, int& idealisMeret, int& C, int& D, Lakas lakas[]);
void rendez(const int N, int lakasTerulet[]);

int felA(const int N, const int A, const int B, const Lakas lakas[]);
int felB(const int N, const int A, const Lakas lakas[], int megB[]);
int felC(const int N, const Lakas lakas[], int megC[]);
int felD(const int N, const int K, const Lakas lakas[]);
int felE(const int N, const int C, const int D, const int idealisAr, const int idealisMeret, const Lakas lakas[]);

int main()
{
    int N, A, B, K, idealisAr, idealisMeret, C, D;
    Lakas lakas[MaxN];

    int megB[MaxN];
    int megC[MaxN] = {0};

    beolvas(N, A, B, K, idealisAr, idealisMeret, C, D, lakas);
    int megA = felA(N, A, B, lakas);
    int dbB = felB(N, A, lakas, megB);
    int dbC = felC(N, lakas, megC);
    int megD = felD(N, K, lakas);
    int megE = felE(N, C, D, idealisAr, idealisMeret, lakas);

    // A FELADAT KIÌR·SA
    if (megA != -1) cout << megA + 1 << endl;
    else cout << "0" << endl;

    // B FELADAT KIÌR·SA
    cout << dbB << " ";
    for (int i = 0; i < dbB; i++) {
        cout << megB[i] + 1 << " ";
    } cout << endl;

    // C FELADAT KIÌR·SA
    for (int i = 0; i < dbC; i++) {
        cout << megC[i] << " ";
    }
    cout << endl;

    // D FELADAT KIÌR·SA
    cout << megD << endl;

    // E FELADAT KIÌR·SA
    cout << megE + 1 << endl;

return 0;
}

void beolvas(int& N, int& A, int& B, int& K, int& idealisAr, int& idealisMeret, int& C, int& D, Lakas lakas[]) {
    cin >> N >> A >> B >> K >> idealisAr >> idealisMeret >> C >> D;

    for (int i = 0; i < N; i++) {
        cin >> lakas[i].ar >> lakas[i].terulet;
    }
}
void rendez(const int N, int lakasTerulet[]) {
    int s;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (lakasTerulet[i] < lakasTerulet[j]) {
                s = lakasTerulet[i];
                lakasTerulet[i] = lakasTerulet[j];
                lakasTerulet[j] = s;
            }
        }
    }
}

int felA(const int N, const int A, const int B, const Lakas lakas[]) {
    int megoldas = -1;

    for (int i = 0; i < N; i++) {
        if (lakas[i].terulet > A && lakas[i].ar > B) {
            megoldas = i;
            break;
        }
    }

    return megoldas;
}
int felB(const int N, const int A, const Lakas lakas[], int megB[]){
    int megoldas = 0;
    int atlagAr;
    int osszAr = 0;

    for (int i = 0; i < N; i++) {
        osszAr += lakas[i].ar;
    }

    atlagAr = osszAr / N;

    for (int i = 0; i < N; i++) {
        if (lakas[i].terulet > A && lakas[i].ar < atlagAr) {
            megB[megoldas] = i;
            megoldas++;
        }
    }

    return megoldas;
}
int felC(const int N,const Lakas lakas[], int megC[]) {
    int nmMin = 10;
    int nmMax = 19;
    int db = 0;

    while (nmMax < 200) {
        for (int i = 0; i < N; i++) {
                if (lakas[i].terulet >= nmMin && lakas[i].terulet <= nmMax)  megC[db]++;
        }

        nmMin += 10;
        nmMax += 10;

        db++;
    }

    return db;
}
int felD(const int N, const int K, const Lakas lakas[]) {
    int megoldas = 0;
    int lakasTerulet[MaxN];
    int kLegK[MaxN];
    int kicsi = 0;for (int i = 0; i < N; i++) {
            if (lakasTerulet[i] > kicsi) {
                kicsi = lakasTerulet[i];
            }
        }

    for (int i = 0; i < N; i++) {
        lakasTerulet[i] = lakas[i].terulet;
    }

    rendez(N, lakasTerulet);
    kLegK[0] = lakasTerulet[0];

    for (int i = 1; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (lakasTerulet[k] > kicsi) {
                kicsi = lakasTerulet[k];
            }
        }

        for (int j = 0; j < N; j++) {
            if (lakasTerulet[j] < kicsi && lakasTerulet[j] > kLegK[i-1]) {
                kLegK[i] = lakasTerulet[j];
            }
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (lakasTerulet[j] == kLegK[i]) megoldas++;
        }
    }

    return megoldas;
}
int felE(const int N, const int C, const int D, const int idealisAr, const int idealisMeret, const Lakas lakas[]) {
    int megoldas = 0;
    int antiErtek[MaxN] = {0};
    int legolcsobb = lakas[0].ar;

    for (int i = 0; i < N; i++) {
        antiErtek[i] = C * ((lakas[i].ar - idealisAr)*(lakas[i].ar - idealisAr)) + D * ((lakas[i].terulet - idealisMeret)*(lakas[i].terulet - idealisMeret));
    }

    int legK = antiErtek[0];

    for (int i = 0; i < N; i++) {
        if (antiErtek[i] < legK) {
            legK = antiErtek[i];
            megoldas = i;
        }
    }

    for (int i = 0; i < N; i++) {
        if (antiErtek[i] == legK && lakas[i].ar < legolcsobb) {
            legolcsobb = lakas[i].ar;
            megoldas = i;
        }
    }

    for (int i = 0; i < N; i++) {
        if (antiErtek[i] == legK && lakas[i].ar == legolcsobb) {
            megoldas = i;
            break;
        }
    }

    return megoldas;
}
