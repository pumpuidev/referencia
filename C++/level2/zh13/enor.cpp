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
	st = norm;
	Next();
}

void Enor::Next()
{
	string sor;
	getline(x,sor);
	if(x.fail() || sor == "")
		st = abnorm;
	else
	{
		stringstream ss(sor);
		ss>>dt.nev;
		dt.ossz = 0;

		int penz;
		string datum;
		ss>>datum;				//megprobalom olvasni az elso datumot (segedvaltozoba, mert a datum nem kell)
		while(!ss.fail())		//ha sikerult datumot olvasni
		{
			ss>>penz;			//akkor olvasok penzt
			dt.ossz += penz;
			ss>>datum;			//majd megprobalom olvasni a kovetkezo datumot
		}

		if(dt.ossz == 13000)
			dt.lastdatum = datum;	//itt amikor ss.fail() volt, a legutolso ertelmes datum orzodott meg!
		else
			dt.lastdatum = "";
	}
}
