#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "HUN"); // ezzel lehet be�ll�tani az �kezetes bet�ket
    int N;
    int M;
    bool hiba; // a cin.fail ellen�rz�shez kell.
    string tmp; // a cin.fail ellen�rz�shez kell.
    do
    {
        cout << "K�rem adja meg a versenyen r�sztvett taul�k sz�m�t: ";
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
        cout << "K�rem adja meg a versenyek sz�m�t: " ;
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
        cout << "adja meg a " <<i+1 <<" tanul� nev�t: ";
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
                cout<< "K�rem adja meg a " << tanulok[i] << " " << j+1<< ". versenyen elert pontszam�t: ";
                cin >> pontszamok[i][j];
            }while (pontszamok[i][j] < -1);
        }
    }
    int j=0;
    int i=0;
    int k=0;
    int s=0; //megsz�ml�l�sban haszn�ljuk
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
        cout << "A versenyen r�szt vettek: ";
        for(int i=0;i<k;i++)
            {
        cout << resztvettek[i] << " ";
            }
    }
    else
    {
        cout << "Senki nem vett r�szt.";
    }

    return 0;

}
