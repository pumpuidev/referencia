#include <iostream>

using namespace std;

const int MAXN = 100;

int paratlan(const int);

int main()
{
    int numbers[MAXN];
    int n, possz;

    cout << "Adja meg a szamok felso hatarat: ";
    cin >> n;

    possz = paratlan(n);
    if (possz > 0) cout << "A paratlan pozitiv egeszek osszege a megadott hatarig: " << possz << endl;
    else cout << "A megadott felso hatarig nincsenek paratlan pozitiv egeszek.\n";

    return 0;
}


int paratlan(const int n) {
    int result = 0;
    int i = 0;

    while (i < n) {
        if (i > 0 && i % 2 == 1) result += i;
        ++i;
    }

    return result;
}
