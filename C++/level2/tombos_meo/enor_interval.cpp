#include "enor_interval.h"

Enor_interval::Enor_interval(int m, int n)	//mindig itt inicializáljuk a felsorolót
{
	this->m = m;
	this->n = n;
}

void Enor_interval::First()
{
	i = m;	//ez a this->m
}

void Enor_interval::Next()	//a next szemantikaja az, hogy ha eddig !End() volt, akkor most "probal" olvasni
{							//es ha nem sikerul, azzal elrontja az endet (ez azért jó így mert mindig elore
	++i;					//olvasunk a ciklusainkban, tehat megkisereljuk az olvasast a ciklusmag vegen,
}							//ez igazza teszi End()-et, es a ciklusmagba ezert nem is lep be ujra.
							//nagyon fontos! a felsorolás VÉGÉN állva az End még hamis. UTÁNA lesz igaz!
bool Enor_interval::End() const
{
	return i > n;	//lehet itt is látni. [m..n]-t sorolunk fel, akkor lett vége, amikor MÁR túlléptünk
}					//(itt most nem vontam le 1-et mint a tombindexelésnél, azt megtettem ott, ahol használom ezt a felsorolót)

int Enor_interval::Current() const
{
	return i;
}
