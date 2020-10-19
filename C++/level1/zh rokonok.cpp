#include <iostream>

using namespace std;

const int maxN=100;

struct Kapcsolat
{
    int szulo, gyerek, ido;
};

bool kozosgyerek(int kinek,int kivel, Kapcsolat T[], int K);

int main()
{
    int N;
    int K;
    string nevek[maxN];
    Kapcsolat T[maxN];
    int parameter[5];


    //beovasas
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin>> nevek[i];
    }
    cin >> K;
    for (int i=0; i<K; i++)
    {
        cin >> T[i].szulo >> T[i].gyerek >> T[i].ido;
    }
    for (int i=0; i<5; i++)
    {
        cin>> parameter[i];
    }
    //kiiras
    /*cerr << N<<endl;
    for (int i=0; i<N; i++)
    {
        cerr << nevek[i]<< endl;
    }
    cerr << K<< endl;
    for (int i=0; i<K; i++)
    {
        cerr <<  T[i].szulo<< " "<< T[i].gyerek<< " "<< T[i].ido<<endl;
    }
    for (int i=0; i<5; i++)
    {
        cerr << parameter[i]<< " ";
    }*/
    //kiir vege
    //a_feladat
    int temp;
    int j=0;
    while (j<K and !(T[j].ido>=parameter[0] and T[j].ido<=parameter[1]) )
    {
        j++;
    }
    if (j<K)
    {
        temp=T[j].gyerek;
        cout << nevek[temp-1]<< endl;
    }
    else
    {
        cout << "NINCS ILYEN EMBER\n";
    }
    //b_feladat
    int gyerek_db[maxN];
    for (int i=0; i<N; i++)
    {
        gyerek_db[i]=0;
    }
    for (int i=0; i<N; i++)
    {
        temp=i+1;
        for (int j=0; j<K; j++)
        {
            if(T[j].szulo==temp)
            {
                gyerek_db[i]++;
            }
        }
    }
    for (int i=0; i<N; i++)
    {
        cout << gyerek_db[i]<< " ";
    }cout << endl;
    //c_feladat
    int c_fel[maxN];
    int db=0;
    for (int i=0; i<N; i++)
    {


        if (gyerek_db[i]>= parameter[2])
        {
           c_fel[db]=i;
           db++;
        }


    }
    cout << db << " ";
    for (int i=0; i<db; i++)
    {
        temp=c_fel[i];
        cout << nevek[temp]<< " ";
    }cout << endl;
    //dfeladat
    int d_fel[maxN];
    db=0;

    for (int i=0; i<N; i++)
    {
        temp=i+1;
        for (int j=0;j<K; j++)
        {
            if (T[j].szulo==parameter[3] and T[j].gyerek==temp)
            {
                d_fel[db]=i;
                db++;
            }


        }

    }
    cout << db << " ";
    for (int i=0; i<db; i++)
    {
        temp=d_fel[i];
        cout << nevek[temp]<< " ";
    }
    cout << endl;

    //e_feladat
    int szulotars[maxN];
    db=0;

    for (int i=0; i<N; i++)
    {
        temp=i+1;
        for (int j=0; j<K; j++)
        {
            if (T[j].szulo!=parameter[4] and kozosgyerek(parameter[4], T[j].gyerek, T, K) and T[j].szulo==temp)
            {
                szulotars[db]=T[j].szulo;
                db++;
                break;
            }
        }
    }
    cout << db<< " ";
    for (int i=0; i<db; i++)
    {
        temp=szulotars[i];
        cout << nevek[temp-1]<< " ";
    }
    cout << endl;














    return 0;
}

bool kozosgyerek(int kinek,int kivel, Kapcsolat T[], int K)//kinek=szulo, kivel=gyerek
{
    int kolkok[maxN];
    int db=0;

    for (int i=0; i<K; i++)
    {
        if (T[i].szulo==kinek)
        {
            kolkok[db]=T[i].gyerek;
            db++;
        }
    }

    for (int i=0; i<db; i++)
    {
        if (kolkok[i]==kivel)
        {
            return true;
        }
    }
    return false;



}


