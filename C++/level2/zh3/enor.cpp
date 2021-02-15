#include "enor.h"
#include<cstdlib>
#include<iostream>
#include<sstream>

using namespace std;

Enor::Enor()
{
    x.open("f.txt");
    if(x.fail())
    {
        cout<<"Fajlmegnyitasi hiba."<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    Next();
}

void Enor::Next()
{
    string sor;
    getline(x,sor);

    if(x.fail())
        st = abnorm;
    else
    {
        st = norm;

        //most a sorban bennvan a kovetkezo (most felsorolando) versenyzo adatainak sora mint string. Ezt kell feldarabolgatni
        //feltettuk hogy helyesen van kitoltve ezert tuti van nev es csapat.
        istringstream ss(sor);

        ss>>dt.nev;
        ss>>dt.csapat;

        //most ott allok a csapat utan. ha van, akkor most egy korsorszam jon, utana meg egy ido. nem fogok tipust ellenorizni mert helyesen van kitoltve a fajl, ha van, akkor a sorszam az szam

        dt.koridok.clear(); //azert mindenkeppen ki kell torolni innen az elozore vonatkozo infokat
        string temp;
        ss>>temp;
        while(!ss.fail()) //elore olvastam, van-e.
        {
            koridoAdat k;

            k.sorszam = atoi(temp.c_str()); //az elore beolvasott cucc lesz a sorszam
            ss>>k.ido;                      //es beolvasom az idejet is
            dt.koridok.push_back(k);    //hozzaadom az igy meghatarozott korido-adatot

            ss>>temp; //majd olvasom elore a KOVETKEZO adatparost. ha nincs, akkor ez failossa teszi az ss-t, tehat a ciklus leall
        }
    }
}

bool Enor::End()
{
    return st == abnorm;
}

Elem Enor::Current()
{
    return dt;
}
