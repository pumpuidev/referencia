#include"enor_mondathossz.h"
#include<iostream>

using namespace std;

Enor_mondathossz::Enor_mondathossz(string fnev)
{
	x.open(fnev.c_str());
}

Enor_mondathossz::~Enor_mondathossz()
{
	x.close();
}

void Enor_mondathossz::First()
{
	sx = norm;
	x>>e;		//e ezert "globalis" az objektumra nezve
	Next();
}

void Enor_mondathossz::Next()
{
	if(x.fail())
		sx = abnorm;	//azert cserelodott meg a sorrend, mert mar elore olvastunk (elso korben a first miatt,
																						//tobbi korben a linker miatt)
	//ALAPSZABALY: next ugy epul fel, hogy olvasok egy egyseget a file-bol, megnezem veget ert-e, ha igen akkor
	//sx=abnorm, kulonben feldolgozom az egyseget
	else
	{
		//pesszimsita linker + szamlalas + fajl felsorolasa
		dx = 0;
		bool l = false;
		//x>>e; nem kell, mert a firstje megvan a First-ben ill. a korabbi Nextekben.
		while(!l && !x.fail())	//gyakorlatilag ez most a "tetelek szekvenciaja" sokszor egymas utan
		{
			if(e != ',' && e != '.')	//szamlalas, most kell a pontot is nezni, hiszen nem dobja el autoamtikusan, mint elvalasztojel
				++dx;
			l = e == '.';		//linker
			x>>e;
		}
	}
}

bool Enor_mondathossz::End()
{
	return sx == abnorm;
}

int Enor_mondathossz::Current()
{
	return dx;
}
