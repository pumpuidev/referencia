#include <iostream>
#include <fstream>

using namespace std;


struct TIdo
{
    int ora, perc;
};
struct TAdat
{
    string nev;
    double atlag;
};

void beolvasNevek(int &m, string nevek[]);
void ellkiirasNevek(int m, const string nevek[]);

int beolvasTAdat(string filename, int &k, TAdat adatok[]);
void ellkiirasTAdat(int k, const TAdat adatok[]);

void filekiirasTAdat(int k, TAdat adatok[]);

void beolvasTIdok(string filename, int &n, TIdo idok[]);
void ellkiirasTIdok(int n, const TIdo idok[]);


int main()
{   const int MAXN = 1000;
    int n,m,k;
    string nevek[MAXN];
    TIdo idok[MAXN];
    TAdat adatok[MAXN];

    beolvasNevek(m, nevek);


    int siker= beolvasTAdat("adatok.txt", k, adatok);
    if (siker==0)
        {
            filekiirasTAdat( k, adatok);
            siker= beolvasTAdat("ujadatok.txt", k, adatok);
        }

    beolvasTIdok("be.txt", n, idok);



    return 0;
}

void beolvasNevek(int &m, string nevek[])
{
    ifstream ifs("nevek.txt");
    if (ifs.is_open())
        {
            m = 0;
            while (!ifs.eof())
                {   m++;
                    ifs>>nevek[m-1];

                    // getline(ifs,nevek[m-1]);

                }

            ifs.close();
            ellkiirasNevek(m, nevek);
        }
    else cout<<"Nem letezo fajl";
}
void ellkiirasNevek(int m, const string nevek[])
{
    for (int i = 1; i<=m; i++)
        {
            cout << i << ". nev: " << nevek[i-1]<< endl;
        };
    cout<<endl;
}

int beolvasTAdat(string filename, int &k, TAdat adatok[])
{

    ifstream ifs(filename.c_str());
    if (ifs.is_open())
        {
            ifs>>k;
            for (int i = 1; i<=k; i++)
                {
                    ifs >> adatok[i-1].nev;
                    ifs >> adatok[i-1].atlag;
                };

            ifs.close();
            ellkiirasTAdat( k, adatok);
            return 0;

        }
    else
        {
            cout<<"Nem letezo fajl";
            return 1;
        }
}
void ellkiirasTAdat(int k, const TAdat adatok[])
{
    for (int i = 1; i<=k; i++)
        {
            cout << i << ". név: " << adatok[i-1].nev << "   atlag: " << adatok[i-1].atlag << endl;
        };
    cout<<endl;
}

void filekiirasTAdat(int k, TAdat adatok[])
{
    ofstream out("ujadatok.txt");
    out<<k<<endl;
    for (int i = 1; i<=k; i++)
        {
            adatok[i-1].atlag=adatok[i-1].atlag+0.2;
            out << adatok[i-1].nev << " " << adatok[i-1].atlag << endl;
        };
    out.close();
}

void beolvasTIdok(string filename, int &n, TIdo idok[])
{
//Helyes bemenetet feltetelezunk
    int ora, perc;
    ifstream ifs(filename.c_str());
    if (ifs.is_open())
        {
            n = 0;
            while (!ifs.eof())
                {
                    ifs >> ora;
                    ifs.ignore(10, ':');
                    ifs >> perc;
                    if (ifs.good())
                        {
                            idok[n].ora = ora;
                            idok[n].perc = perc;
                            n++;
                        }
                }
            ifs.close();
            ellkiirasTIdok(n, idok);
        }
    else cout<<"Nem letezo fajl";
}

void ellkiirasTIdok(int n, const TIdo idok[])
{
    for (int i = 1; i<=n; i++)
        {
            cout << i << ". idopont: " << idok[i-1].ora << ":" << idok[i-1].perc << endl;
        };
    cout<<endl;
}

