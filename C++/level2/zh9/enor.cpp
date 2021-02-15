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
	Next();
}

void Enor::Next()
{
	string sor;
	getline(x,sor);
	if(x.fail() || sor == "")
		sx = abnorm;
	else
	{
		sx = norm;
		stringstream ss(sor);
		ss>>dx.nev;
		dx.befiz.clear();		//kiszedem az elozo diak befizeteseit...

		string seged;
		ss>>seged;				//megprobalom olvasni az elso datumot
		while(!ss.fail())		//has sikerult datumot olvasni
		{
			Par par;
			par.datum = seged;	//akkor elmentem
			ss>>seged;			//es beolvasom a penzt is
			par.penz = atoi(seged.c_str());	//es persze azt is elmentem
			dx.befiz.push_back(par);		//es berakom a tombbe amit sikerult osszeallitani
			ss>>seged;			//majd megprobalom olvasni a kovetkezo datumot
		}
	}
}

Diak Enor::Current() const
{
	return dx;
}

bool Enor::End() const
{
	return sx == abnorm;
}
