#include <iostream>

using namespace std;

int n;

void elso (int evek []) {
    int max = -1;
    for (int i = 0; i < n-1; i++) {
        int akt = evek[i+1] - evek[i];
        if (akt > max) max = akt;
    }
    cout << max << endl;
}
void masodik (int csucsok []) {
    int eddigiek [n];
    int cs = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (csucsok[i] == eddigiek[j]) {
                cs++;
                break;
            }
        }
        eddigiek[index] = csucsok[i];
        index++;
    }
    cout << cs << endl;
}
void harmadik (int evek []) {
    for (int i = n-1; i > 1; i--) {
        if (evek[i] - evek[i-1] != 1) {
            cout << (evek[i]-1) << endl;
            break;
        }
    }
}
void negyedik (int evek[], int csucsok []) {
    int db = 0;

    for (int i = n-1; i > 1; i--) {
        int db = 0;
        for (int j = (i-1); j > 1; j--) {
            if (evek[i] == evek[j])
        }
    }
}
void otodik () {}

int main()
{
    cin >> n;
    int evek [n];
    int csucsok [n];
    for (int i = 0; i < n; i++) {
        cin >> evek[i];
        cin >> csucsok[i];
    }
    elso(evek);
    masodik(csucsok);
    harmadik(evek);
    return 0;
}
