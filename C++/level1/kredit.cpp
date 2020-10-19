#include <iostream>

using namespace std;

int main()
{
    int i;
    cout << "kreditossz: ";
    cin >> i;
    if (i<0)
    {
        cout << "tul kicsi" << endl;
        exit(1);
    }
    if (1000<i)
    {
        cout << "tul nagy" << endl;
        exit(1);
    }

    cout << "kreditatlag: " << i/30.0 << endl;
    return 0;
}
