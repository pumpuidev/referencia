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

		adat.azon = "";				//ebbe epitjuk a stringet
		string seged1,seged2;		//kettot olvasunk, mert amikor megtalaljuk a datumot kell az elozo is
		ss>>seged1>>seged2;			//az elso biztosan a nev resze
		while(!ss.fail() && !datum(seged2))
		{
			adat.azon += seged1;	//ezert is fuzzuk hozza
			seged1 = seged2;		//de ezt majd csak akkor, ha a kov. korben se talalunk datumot
			ss>>seged2;
		}
		//most: seged2-ben van a datum (vagy ss.fail() van), seged1-ben a kkoltseg

		int kkoltseg = atoi(seged1.c_str());
		adat.osszbefiz = 0;
		adat.jolfizetett = false;	//pessz. linker-szeru

		while(!ss.fail())	//ha egyaltalan volt
		{
			int penz;
			ss>>penz;
			adat.osszbefiz += penz;
			adat.jolfizetett = adat.jolfizetett || penz == kkoltseg;
			ss>>seged2;			//kovetkezo par elso elemenek olvasasa
		}

		adat.befizette = adat.osszbefiz == kkoltseg * 12;
	}
}

bool Enor::datum(string s)
{
	return
		s.size() == 10 &&
		isdigit(s[0]) &&
		isdigit(s[1]) &&
		isdigit(s[2]) &&
		isdigit(s[3]) &&
		s[4] == '.' &&
		isdigit(s[5]) &&
		isdigit(s[6]) &&
		s[7] == '.' &&
		isdigit(s[8]) &&
		isdigit(s[9]);
}
