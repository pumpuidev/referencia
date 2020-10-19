#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //1. dekl: spec be, ki
    double a,b,c;
    bool van;
    double x1, x2;
    //2. be: spec be
    bool rossz;
    do {
        cout << "a = ";
        cin >> a;
        rossz = !(a!=0);
        if (rossz) {
            cout << "hiba" << endl;
        }
    } while (rossz);
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    //3. feld: stuki
    double d = b*b - 4*a*c;
    if (d>=0) {
        van = true;
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
    } else {
        van = false;
    }
    //4. ki
    if (van) {
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else {
        cout << "Nincs megoldas" << endl;
    }

    return 0;
}
