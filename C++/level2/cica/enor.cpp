#include"enor.h"
#include<cstdlib>
#include<sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"Mijau."<<endl;
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::Next()
{
    string sor;				//ha tudjuk hogy hany "szo" van egy sorban, akkor teljesseggel meguszhato a getline,
    getline(x,sor);			//igy viszont nem, hiszen majd ennek a fail()-jebol fogjuk tudni, meddig voltak az akt. cicara vonatkozo adatok

    if(x.fail())
        vege = true;
    else
    {
		if(sor != "")	//ha van koztuk ures sor, azt kihagyjuk (vigyazat ezt ha a fentebbi ifbe irjuk, akkor konkretan az elso koztes ures sornal kilep)
		{
			stringstream ss(sor);
			ss>>akt.nev>>akt.kor;

			akt.kolykok.resize(0);
			string seged;		//kettesevel olvasunk, mert a gyerekek utan van meg egy szin is,
			string seged2;		//tehat a kolykok tombbe csak akkor szabad berakni az olvasott stringet,
			ss>>seged;			//ha nem az volt a tokutolso a sorban!
			while(ss>>seged2)
			{
				akt.kolykok.push_back(seged);
				seged = seged2;
			}

			akt.szin = seged;	//az utolso sikeresen beolvasott elem a szin
		}
		else
			Next();
    }
}
