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
		dx.nev = "";
		dx.befiz.clear();

		string seged;
		ss>>seged;							//beolvasom a nev elso reszet
		while(!ss.fail() && !datum(seged))	//addig olvasok, amig egyreszt van, masreszt nem datum
		{
			dx.nev += seged + " ";
			ss>>seged;
		}

		dx.nev = dx.nev.substr(0,dx.nev.size()-1);
		//ez csak hogy szep legyen: midnen nev vegere kerult egy felesleges szokoz, azt szedi le
		//substr - reszszo-kepzes: elso param.: hanyadik indextol, masodik param.: milyen hosszan

		//ezen a ponton most vagy vege van a sornak (nem volt datum-penz par),
		//vagy be van olvasva az elso ilyennek a datum resze
		//azaz segedben most "jo esetben" megvan a datum, ezert nem olvassuk "elore" megegyszer.
		//(de a ciklus resze nem valtozott)
		while(!ss.fail())
		{
			Par par;
			par.datum = seged;
			ss>>seged;
			par.penz = atoi(seged.c_str());
			dx.befiz.push_back(par);
			ss>>seged;
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

bool Enor::datum(string d)
{
	//isdigit: megmondja egy karakterrol, hogy szamjegy-e
	return
		d.size() == 10 &&	//hossza
		isdigit(d[0]) &&	//ev
		isdigit(d[1]) &&
		isdigit(d[2]) &&
		isdigit(d[3]) &&
		d[4] == '.' &&
		isdigit(d[5]) &&	//ho
		isdigit(d[6]) &&
		d[7] == '.' &&
		isdigit(d[8]) &&	//nap
		isdigit(d[9]);
}
