#include"enor.h"
#include<sstream>
#include<cstdlib>

using namespace std;

Enor::Enor(std::string fnev)
{
	x.open(fnev.c_str());
}

Enor::~Enor()
{
	x.close();
}

void Enor::First()
{
	if(x.fail())
		vege = true;
	else
		Next();
}

void Enor::Next()
{
	//tovabbra is ez a next logikaja:
	//1. olvasunk egy elemet
	//2. ha nem sikerult, vege
	//3. ha sikerult, feldolgozzuk... ez a "feldolgozas" ebben a valtozatban a legkomolyabb

	x>>o.nev;		//1. beolvasok egy elemet
	if(x.fail())	//2. ha nem sikerult
	{
		vege = true;
	}
	else			//3. feldolgozas
	{
		vege = false;
		string s;
		getline(x,s);	//itt a sorban mar nincs benne az orszagnev, hisz beolvastam mar
		stringstream ss(s);

		o.vdb = 0;	//szamlalas tetel
		o.ossz = 0;	//osszegzes tetel
		string sv;
		ss>>sv;
		while(!ss.fail())
		{
			int szam = atoi(sv.c_str());
			if(szam != 0 || sv == "0")	//ha szam volt
			{
				++o.vdb;		//az egy lakossagszam volt -> volt egy varos
				o.ossz += szam;	//es ime a lakossaga
			}
			ss>>sv;
		}
		o.ossz *= 1000; //csak hogy ezt se a foprogramba kelljen... :)
	}
}

Orszag Enor::Current() const
{
	return o;
}

bool Enor::End() const
{
	return vege;
}
