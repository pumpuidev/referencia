#include <iostream>

using namespace std;

int main()
{
    //1
    int n; //be
    int o; //ki
    bool van; //ki
    //2
    cout << "n=";
    cin>>n;
    //3
    int i;
    i = 2;
    while (i<n && n % i != 0) {
        i = i + 1;
    }
    van = i<n;
    if (van) {
        o = i;
    }
    //4
    if (van) {
        cout << "Oszto:" << o << endl;
    } else {
        cout << "nincs" << endl;
    }


    return 0;
}
