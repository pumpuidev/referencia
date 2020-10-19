#include <iostream>
#include <fstream>
 
using namespace std;
 
const int maxN=50;
 
struct indulokt
{
    string nev;
    int vszamdb=1;
    int vszami[maxN];
    float eredmeny[maxN];
    int helyezes[maxN];
};
void adatrogzito(int& n, int& v, int& db, indulokt indulok[], string vszamok[], string& nev)
{
    int i;
    string tmpnev;
    ifstream fin_stream("input.txt",ios::in);
    if (fin_stream.fail()) cerr << "A MEGADOTT FAJL NEM TALALHATO.\n";
    fin_stream>>n;
    fin_stream>>v;
    getline(fin_stream, tmpnev);
    for(int j=0;j<v;j++)
    {
        getline(fin_stream, vszamok[j]);
    }
    for(int j=0;j<n;j++)
    {
        i=0;
        getline(fin_stream, tmpnev);
        while(i<j&&tmpnev!=indulok[i].nev)
        {
            i++;
        }
        if(i<j)
        {
            indulok[i].vszamdb++;
            fin_stream>>indulok[i].vszami[indulok[i].vszamdb-1];
            fin_stream>>indulok[i].eredmeny[indulok[i].vszamdb-1];
            fin_stream>>indulok[i].helyezes[indulok[i].vszamdb-1];
        }
        else
        {
            indulok[db].nev=tmpnev;
            fin_stream>>indulok[db].vszami[indulok[j].vszamdb-1];
            fin_stream>>indulok[db].eredmeny[indulok[j].vszamdb-1];
            fin_stream>>indulok[db].helyezes[indulok[j].vszamdb-1];
            db++;
        }
        getline(fin_stream, tmpnev);
    }
    getline(fin_stream, nev);
    fin_stream.close();
}
void afeladat(int db, string nev, indulokt indulok[], string vszamok[])
{
    int m=0;
    int i=0;
    while(i<db&&nev!=indulok[i].nev)
    {
        i++;
    }
    if(i<db)
    {
        for(int j=1;j<indulok[i].vszamdb;j++)
        {
            if(indulok[i].helyezes[j]<indulok[i].helyezes[m])
            {
                m=j;
            }
        }
    }
    cerr<<vszamok[indulok[i].vszami[m]-1] << endl;
}
void bfeladat(int n, int v,int db, indulokt indulok[])
{
    int vdarab[v]={0};
    for(int i=0; i<db;i++)
    {
        for(int j=0; j<indulok[i].vszamdb; j++)
        {
            if(indulok[i].vszami[j]!=0)
            {
                vdarab[indulok[i].vszami[j]-1]++;
            }
        }
    }
    for(int i=0; i<v; i++)
    {
        cerr<<vdarab[i]<<" ";
    }
    cerr<<endl;
}
void cfeladat(int db, indulokt indulok[], string nev, string vszamok[])
{
    int i=0;
    while(i<db&&nev!=indulok[i].nev)
    {
        i++;
    }
    if(i<db)
    {
        cerr<<indulok[i].vszamdb;
        for(int j=0;j<indulok[i].vszamdb;j++)
        {
            cerr<<";"<<vszamok[indulok[i].vszami[j]-1];
        }
    }
    cerr<<endl;
}
void dfeladat(indulokt indulok[], int db)
{
    cerr<<db;
    int tmp;
    for(int i=0; i<db;i++)
    {
        tmp=0;
        cerr<<";"<<indulok[i].nev;
        for(int j=0;j<indulok[i].vszamdb;j++)
        {
            if(indulok[i].helyezes[j]<4)
            {
                tmp++;
            }
        }
        cerr<<";"<<tmp;
    }
}
int main()
{
    int db = 0;
    int n;
    int v;
    string vszamok[maxN];
    string nev;
    indulokt indulok[maxN];
    adatrogzito(n, v, db, indulok, vszamok, nev);
    afeladat(db, nev, indulok, vszamok);
    bfeladat(n, v, db, indulok);
    cfeladat(db, indulok, nev, vszamok);
    dfeladat(indulok, db);
    return 0;
}