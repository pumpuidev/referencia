#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //i.deklaracio <-- spec be, ki
    double cels;
    double fahr;
    const double MINHOM = -89;
    const double MAXHOM = 58;
    //2. beolvasas <-- spec be
    cout << "Celsius: ";
    cin >> cels;
    if (cels < MINHOM || cels > MAXHOM)
    {
        cout << "Nem jo." << endl;
        exit (1);
    }
    //3. feldolgozás <-- algoritmus (stuki)
    fahr = (cels * (9.0 / 5)) + 32;
    //4. kiiras <-- spec ki
    cout << "Fahrenheit: " << fahr << endl;

    return 0;
}
