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
		sx = abnorm;
	else
		Next();
}

void Enor::Next()
{
	if(x>>dx)
		sx = norm;
	else
		sx = abnorm;
}

Data Enor::Current() const
{
	return dx;
}

bool Enor::End() const
{
	return sx == abnorm;
}

istream& operator>>(istream& is, Varos& d)	//beolvaso operator egy varoshoz, a gondot a nevenek a hossza jelentheti
{
	string s;
	int i;

	bool szam = false;	//linker tetel az elso szamig
	d.nev = "";		//osszegzes tetel a nev beolvasa, ezt inicializaljuk itt
	while(!szam && !is.fail())	//most az elso szam karakterig sorolunk fel, az lesz a lakossagszam ugyanis!
	{
		is>>s;
		if(!is.fail())	//ha volt egyaltalan...
		{
			i = atoi(s.c_str());
			if(s != "0" && i == 0)	//akkor megnezzuk, hogy ugye nem szam-e
				d.nev += s + " ";	//mert akkor a nev resze
			else
				szam = true;		//ha szam, akkor meg szam :)
		}
	}
	if(!is.fail())
	{
		d.lakok = i;	//megvolt a linker, az "elem"-nek megfelelo valzotojaban ott van a keresett elem, azaz a szam
		d.nev = d.nev.substr(0, d.nev.size()-1);	//itt meg elhagyom az utolso karaktert, mert az egy felesleges szokoz
	}

	return is;
}

ostream& operator<<(ostream& os, const Varos& d)	//kiiro operator, igazabol itt es most ez felesleges!
{
	os<<d.nev<<" "<<d.lakok;
	return os;
}

istream& operator>>(istream& is, Data& d)	//beolvaso operator, gyakorlatilag ez a "read" fuggveny
{
	string s;
	getline(is,s);		//beolvasom a sort
	if(!is.fail())		//ha sikerult...
	{
		stringstream ss(s);	//..akkor feldarabolva feldolgozom
		ss>>d.orszag;
		Varos v;
		d.varosok.resize(0);	//ez fontos, kulonben az osszes varost megorizne ami eddig volt
		while(ss>>v)		//amig vannak varosok, addig olvasom
			d.varosok.push_back(v);
	}

	return is;
}

ostream& operator<<(ostream& os, const Data& d)	//kiiro operator, igazabol itt es most ez felesleges!
{
	os<<d.orszag<<" ";
	for(size_t i=0;i+1<d.varosok.size();++i)
		os<<d.varosok[i]<<" ";
	if(d.varosok.size()>0)
		os<<d.varosok[d.varosok.size()-1];
	return os;
}
