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
		dt.nev = "";
		dt.ossz = 0;
		dt.reszletek = 0;

		string nevseged;
		ss>>nevseged;
		while(!ss.fail() && !datum(nevseged))
		{
			dt.nev += nevseged + " ";
			ss>>nevseged;
		}
		dt.nev = dt.nev.substr(0,dt.nev.size()-1); //utolso szokoz elhagyasa

		//most vagy ss.fail van (ha nem volt befizetes) vagy nevsegedben ott a datum
		string date;
		date = nevseged;	//azert adtam at, hogy ha o az utolso datum, akkor megmaradjon.
		int penz;
		while(!ss.fail())		//ha sikerult datumot olvasni
		{
			++dt.reszletek;		//akkor van egy reszlet...
			ss>>penz;			//akkor olvasok penzt
			dt.ossz += penz;
			ss>>date;			//majd megprobalom olvasni a kovetkezo datumot
		}

		if(dt.ossz == 13000)
			dt.lastdatum = date;	//itt amikor ss.fail() volt, a legutolso ertelmes datum orzodott meg!
		else
			dt.lastdatum = "";
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
