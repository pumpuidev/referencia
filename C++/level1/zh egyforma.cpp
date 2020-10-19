
#include <iostream>

using namespace std;

int main()
{
    int n,j;

    const int MAXN = 100;
    int x[MAXN];

    bool van_egyforma;
    bool rossz;

    do
    {
        cout << "A sorozat db szama: ";
        cin >> n;
        rossz = cin.fail() || !(n>=0);
        if (rossz)

        {
            cout << "Hiba! Probald ujra!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    while (rossz);

    for (int i=0; i<=n-1; i++)
    {
        do
        {
            cout << i+1 << ". elemszam: ";
            cin >> x[i];
            rossz =  cin.fail() || !(x[i]>0);
            if (rossz)
            {
                cout << "Probald ujra!" << endl;
                 cin.clear();
            cin.ignore(1000,'\n');
            }
        }
        while (rossz);

    }

    int i=0;
    van_egyforma = false;
    while (i<=n-1 && !(van_egyforma))
    {
        j=i+1;
        while (j<=n && !(x[i]==x[j]))
        {
            j=j+1;
        }
        van_egyforma = j<=n;
        i=i+1;
    }

      if (van_egyforma){
        cout << "Van egyforma." << endl;

      }

    else {
        cout << " Nincs egyforma." << endl;
    }



    return 0;
}
