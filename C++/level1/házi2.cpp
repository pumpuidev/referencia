#include <iostream>

using namespace std;

int main()
{
    int a=0;
    int b=0;
    int eredmeny=0;
    cout << "Adj meg egy szamot:" << endl;
    cin >> a;
    cout << "Add meg a másik számot:" << endl;
    cin >> b;
    for(int i=0; i<a; i++)
    eredmeny+=b;
    cout << eredmeny ;
    return 0;
}
