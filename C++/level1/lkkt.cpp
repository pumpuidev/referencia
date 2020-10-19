#include <iostream>

using namespace std;

int lkkt(int, int);
void csere(int&, int&);

int main()
{
    int a, b, legk;

    do {
        cout << "Adja meg az elso szamot: ";
        cin >> a;
        cout << "Adja meg a masodik szamot: ";
        cin >> b;

        if (a <= 0 || b <= 0 || cin.fail()) {
            cout << "A program ket pozitiv egeszet var.\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (a <= 0 || b <= 0);

    legk = lkkt(a, b);
    cout << "A ket megadott szam legkisebb kozos tobbszorose: " << legk << endl;

    return 0;
}

int lkkt(int a, int b) {
    int tobbszoros, maradek, oszto;

    tobbszoros = a * b;

    if (a < b) csere(a, b);
    maradek = a % b;

    while (maradek > 0) {
        a = b;
        b = maradek;
        maradek = a % b;
    }

    oszto = b;
    tobbszoros /= oszto;

    return tobbszoros;
}

void csere(int& a, int& b) {
    int s;

    s = a;
    a = b;
    b = s;
}
