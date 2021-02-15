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
		ss>>dx.azon;
		ss>>dx.kkoltseg;
		dx.befiz.clear();	//elozobol megorokolt adatokat toroljuk

		string seged;
		ss>>seged;			//elso datum beolvasasa
		while(!ss.fail())	//ha egyaltalan volt
		{
			Par par;
			par.datum = seged;
			ss>>seged;
			par.penz = atoi(seged.c_str());
			dx.befiz.push_back(par);
			ss>>seged;			//kovetkezo par elso elemenek olvasasa
		}
	}
}
