#include <iostream>

using namespace std;

int main() {
    //1.dekl
    int n;
    const int MAXN = 100;
    double kg[MAXN];
    double ossz;
    //2.beolv
    bool rossz;
    do {
        cout << "Hanyan hoztak papirt: ";
        cin >> n;
        rossz = cin.fail() || !(n>=0 && n<=MAXN);
        if (rossz) {
            cout << "Rossz" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (rossz);

    for (int i = 0; i<=n-1; i++) {
        do {
            cout << i+1 << ".kg: ";
            cin >> kg[i];
            rossz=!(kg[i]>0);
            if (rossz) {
                cout <<"Rossz" << endl;
                cin.clear();
                cin.ignore (1000, '\n');

            }
        } while (rossz);
    }
    //3.feldolg.
    ossz = 0;
    for (int i = 0; i<=n-1; i++) {
        ossz = ossz + kg[i];
    }
//4. ki
    cout << "Osszesen: " << ossz << "kg" << endl;
    return 0;
}
