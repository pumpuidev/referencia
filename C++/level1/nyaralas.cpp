#include <iostream>

using namespace std;

int main()
{
    const int MAXM = 100;
    double koltes[MAXM];
    int N;
    int M;
    int DB;

    cout << "Letszam: ";
    cin >> N;

    cout << "Napok szama: ";
    cin >> M;

    DB=0;
    for (int i=0; i<=M-1; i++){
        cout << i+1 <<". nap koltsege: ";
        cin >> koltes[i];
        if (koltes[i] > N*100) {
            DB = DB+1;
        }
    }

    cout << "Megfelelo napok szama: " << DB << endl;
}
