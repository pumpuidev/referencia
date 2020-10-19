#include <iostream>

using namespace std;

int main()
{
    //1. deklaracio: spec be, ki
    double x, y;
    int sn;
    //2. beolvasas: spec be

    cout << "x: ";
    cin >> x;
    cout << "y ";
    cin >> y;
    //3. feldolgozas: stuki
    if (x>=0)
    {
        if (y>=0)
        {
            sn = 1;

        }
        else
        {
            sn = 4;
        }
    } else {
        if (y>=0) {
            sn = 2;
        } else {
            sn = 3;
        }
    }

    //4. kiiras: spec ki
    cout << "Siknegyed: " << sn << endl;

    return 0;
}
