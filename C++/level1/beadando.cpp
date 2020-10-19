#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "HUN"); // ezzel lehet beállítani az ákezetes betûket
    int N;
    int M;
    bool hiba; // a cin.fail ellenörzéshez kell.
    string tmp; // a cin.fail ellenörzéshez kell.
    do
    {
        cout << "Kérem adja meg a versenyen résztvett taulók számát: ";
        cin >> N;
        hiba=cin.fail();
        if(hiba)
         {
            cout << "Hibas beolvasas" << endl;
            cin.clear(); getline(cin, tmp, '\n');
         }
    }while (hiba || N < 0);
    string tanulok[N];

    do
    {
        cout << "Kérem adja meg a versenyek számát: " ;
        cin >> M;
         hiba=cin.fail();
        if(hiba)
         {
            cout << "Hibas beolvasas" << endl;
            cin.clear(); getline(cin, tmp, '\n');
         }
    }while (hiba || M < 0);
    for (int i=0;i<N;i++)
    {
        cout << "adja meg a " <<i+1 <<" tanuló nevét: ";
        cin >> tanulok[i];

    }
    int pontszamok[N][M];
    for(int i=0;i<N;i++)
    {
        cout  << endl;
        for(int j=0;j<M;j++)
        {
            do
            {
                cout<< "Kérem adja meg a " << tanulok[i] << " " << j+1<< ". versenyen elert pontszamát: ";
                cin >> pontszamok[i][j];
            }while (pontszamok[i][j] < -1);
        }
    }
    int j=0;
    int i=0;
    int k=0;
    int s=0; //megszámlálásban használjuk
    string resztvettek[N];
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            s=s+pontszamok[i][j];
        }
        if(!(s==-M))
        {
            resztvettek[k]=tanulok[i];
            k++;

        }

    }


    if(!(k==0))
    {
        cout << "A versenyen részt vettek: ";
        for(int i=0;i<k;i++)
            {
        cout << resztvettek[i] << " ";
            }
    }
    else
    {
        cout << "Senki nem vett részt.";
    }

    return 0;

}
