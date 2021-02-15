#include <iostream>
#include <fstream>
#include <vector>
#include "beolvasas.h"
#include "csoki.h"

/*
	Feladat:
	Egy csokigyár közvéleménykutatást tartott arról,
	mennyire népszerû egy bizonyos terméke.
	Az alanyoktól megkérdezték a korukat,
	valamint azt, hogy egy ötös skálán hányasra értékelik a kérdéses terméket.
	Igaz-e, hogy nincs olyan korosztály,
	amelyik átlagban 4-esnél rosszabbra értékelte volna?
	Azt, hogy mi számít "korosztálynak",
	a vállalat maga dönti el, egy megfelelõen megválasztott skála alapján.
*/

using namespace std;

int main()
{
    cout<<"--== Csoki nepszeruseg-index szamolo program ==--"<<endl;

	vector<int> korosztalyok;
	vector<vector<int> >osztalyzatok;

	string uzenet = "Valaszd meg az adatbekeres modjat (f/b)";
	char mod = beolv_char('f','b', uzenet);

	//beolvasas:
	bool siker;			//csak akkor szamolunk, ha sikeres a beolvasas
	if(mod == 'f')
	{
		string fnev;
		cout<<"Add meg a korosztalyokat tartalmazo fajl nevet!"<<endl;
		cin>>fnev;
		ifstream ifs(fnev.c_str());
		siker = beolv_korosztalyok(korosztalyok, ifs, false);
		ifs.close();

		if(siker)
		{
			cout<<"Add meg az osztalyzatokat tartalmazo fajl nevet!"<<endl;
			cin>>fnev;
			ifstream ifs(fnev.c_str());
			siker = beolv_osztalyzatok(osztalyzatok, korosztalyok, ifs, false);
			ifs.close();
		}
	}
	else
	{
		cout<<"Add meg a korosztalyokat!"<<endl;
		siker = beolv_korosztalyok(korosztalyok, cin, true);

		if(siker)
		{
			cout<<"Add meg az osztalyzatokat!"<<endl;
			siker = beolv_osztalyzatok(osztalyzatok, korosztalyok, cin, true);
		}
	}

	if(siker)
	{
		//beolvasott adatok kiirasa:
		cout<<"A korosztalyok:"<<endl;
		kiir_korosztalyok(korosztalyok);
		cout<<"Az osztalyzatok:"<<endl;
		kiir_osztalyzatok(osztalyzatok);

		//eredmeny kiirasa:
		if(optlinker(osztalyzatok))
			cout<<"Nincs olyan korosztaly, amelyik atlagban 4-esnel rosszabra ertekeli a cuccot"<<endl;
		else
			cout<<"Van olyan korosztaly, amelyik atlagban 4-esnel rosszabra ertekeli a cuccot"<<endl;

		return 0;
	}
	else
	{
		cout<<"Beolvasasi hiba!"<<endl;
		return 1;
	}
}
