#include <iostream>

using namespace std;

int main() {

//1. deklaracio <-- spec be, ki
    int a, b;
    bool oszthatoe;
//2. beolvasas <-- spec be
    cout << "A = " << endl;
    cin >> a ;
    cout << "B = ";
    cin >> b;
   // if (b==0)
      //  cout << "b 0 "
    //3. feldolgozas <-- alg
    if (a % b == 0) {
        oszthatoe = true;
    } else {
        oszthatoe = false;
    }
    //4. kiiras <-- spec ki
    if (oszthatoe == true) {
        cout << "Oszthato" << endl;
    } else {
        cout << "Nem oszthato" << endl;
    }
    return 0;
}
