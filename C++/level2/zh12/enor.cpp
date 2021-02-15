#include"enor.h"
#include<sstream>
#include<cstdlib>

using namespace std;

Enor::Enor(string fnev)
{
	x.open(fnev.c_str());
	if(x.fail())
	{
		cerr<<"Nincs file.";
		exit(1);
	}
}

Enor::~Enor()
{
	x.close();
}

void Enor::First()
{
	vege = false;
	Next();
}

void Enor::Next()
{
	string sor;
	getline(x,sor);
	if(x.fail() || sor == "")
		vege = true;
	else
	{
		stringstream ss(sor);
		dx.befiz.clear();	//elozobol megorokolt adatokat toroljuk
		dx.azon = "";		//ez is fontos!

		//az a gond, hogy az azonositoban lehet szam, a kkoltseg is szam
		//es a datum is ki tud ertekelodni szamma.
		//az lesz a hatar, ha "datum alaku" a beolvasott string.
		//viszont ameddig nem olvastuk be a datumot, addig nem tudjuk, hogy hol van vege
		//az azonositonak es melyik a kkoltseg. ezert csak akkor konkatenalhatom hozza a keszulo
		//azonositohoz a beolvasott stringet, ha se o, se az utanalevo nem datum.
		//mert ha az utanalevo datum, akkor az akt. elem a kozos koltseg.
		//ezt ugy tudom biztositani hogy eloszor kettot olvasok be, aztan egyesevel
		//es az elsot irom mindig ki a az azonositoba, a masodikat pedig "elmentem".
		//az elejen kettot olvasni szabad, hiszen minden azonosito legalabb egy szavas es
		//van kozos koltseg is, tehat van legalabb ket szo minden sorban

		string seged1,seged2;
		ss>>seged1>>seged2;			//elso ket adat megvan
		while(!ss.fail() && !datum(seged2))	//ha volt, es nem datum, akkor olvasunk tovabb
		{
			dx.azon += seged1;	//de elobb epitjuk az azonositot
			seged1 = seged2;	//es elmentjuk azt, amirol meg nem tudjuk, a kozos koltseg-e.
			ss>>seged2;
		}
		//itt most vagy ss.fail() (azaz nincs datum-ertek par egyaltalan)
		//vagy az elso datum van seged2-ben
		//seged1-ben pedig ami elotte van, azaz a kkoltseg
		dx.kkoltseg = atoi(seged1.c_str());

		while(!ss.fail())
		{
			Par par;
			par.datum = seged2;		//tehat ha nem volt fail akkor itt van a datum
			ss>>seged2;				//olvassik be a szamot is
			par.penz = atoi(seged2.c_str());
			dx.befiz.push_back(par);
			ss>>seged2;				//kovetkezo par datumanak olvasasa
		}
	}
}

bool Enor::datum(string s)
{
	if(s.size() == 10)
	{
		int ev = atoi(s.substr(0,4).c_str());	//0,1,2,3-as indexek
		int ho = atoi(s.substr(5,2).c_str());	//5,6-os indexek
		int nap= atoi(s.substr(8,2).c_str());	//a ket utolso (8,9) index

		if(s[4] == '.' && s[7] == '.' && ev == 2014 && ho >=1 && ho <=5 && nap >= 1 && nap <=31)
			return true;
	}

	return false;	//erre csak akkor fut ra, ha az egyik if nem volt igaz.

}
