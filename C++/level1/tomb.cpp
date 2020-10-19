#include <iostream>

using namespace std;

int main()
{
    //1.dekl: spec be, ki
    int n;
    string nap;
    const string napok[7] = {"h","k","sze","cs","p","szo","v"};
    //2.beolv:
   bool rossz;
   do {
    cout << "n: ";
    cin >> n;
    rossz = !(1<=n && n<=7);
    if (rossz) {
        cout << "1 es 7 kozt kell" << endl;
    }
} while (rossz);
    //3. feldolgozas: stuki
    nap = napok[n-1];
    //4. ki
    cout << "Het napja: " << nap << endl;

    return 0;
}
