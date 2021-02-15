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
		ss>>adat.azon;
		adat.osszbefiz = 0;
		int kkoltseg;
		ss>>kkoltseg;	//ez nem is fontos nekunk, ezert csak lokalis segedvaltozo
		//(persze lehetne olyan a feladat, hogy kene!)

		string seged;		//datumhoz
		ss>>seged;			//elso datum beolvasasa
		while(!ss.fail())	//ha egyaltalan volt
		{
			int penz;
			ss>>penz;
			adat.osszbefiz += penz;
			ss>>seged;			//kovetkezo par elso elemenek olvasasa
		}

		adat.befizette = adat.osszbefiz == kkoltseg * 12;
	}
}
