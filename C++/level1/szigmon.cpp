#include <iostream>

using namespace std;

int main()
{
    const int MAXN=100;
    int n;
    bool mon;
    double h[MAXN];
    bool rossz;

    do{
        cout << "Az elemek szama: ";
        cin >> n;
        rossz = !(n>=2) || cin.fail() || n>MAXN;
        if (rossz){
            cout << "Hibas szam!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }while(rossz);

    for (int i=0; i<=n-1; i++){
        do{
            cout << "A(z) " << i+1 << ". elem: ";
            cin >> h[i];
            rossz = cin.fail();
            if (rossz){
                cout << "Nem szam!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(rossz);
    }

    int i;
    i=1;
    while(i<=n-1 && h[i]>h[i-1]){
        i++;
    }
    mon=i>n-1;

    if (mon){
        cout << "A sorozat szigoru monoton novekvo" << endl;
    } else {
        cout << "A sorosat nem szigoru monoton novekvo" << endl;
    }
    return 0;
}
