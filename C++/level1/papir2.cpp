#include <iostream>

using namespace std;

int main()
{
    double ossz;
    int N;
    const int MAXN = 100;
    double kg[MAXN];
    bool rossz;

    do{
        cout << "Resztvevok szama: ";
        cin >> N;
        rossz = cin.fail() || !(N>=0 && N<=MAXN);
        if (rossz){
            cout << "Hibas resztvevo szam!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(rossz);

    ossz=0;
    for (int i = 0; i<=N-1; i++){
        do{
            cout << "A(z) " << i+1 << ". resztvevo altalt gyujtott mennyiseg: ";
            cin >> kg[i];
            rossz = cin.fail() && !(kg[i]>0);
            if (rossz){
                cout << "Hibas mennyiseg!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while(rossz);
    }

    for (int i = 0; i<=N-1; i++){
        ossz=ossz+kg[i];
    }
    cout << "Osszegyujtott papir mennyisege: " << ossz << endl;
    return 0;
}
