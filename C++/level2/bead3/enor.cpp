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
		st = abnorm;
	else
		Next();
}

void Enor::Next()	//most hogy nincsenek operatorok ez lett bonyolultabb,
{					//de a modszer elonye, hogy tenyleg csak ez a next ami valtozik feladatrol feladatra
	//mindig igy mukodik a next:
	//1. olvasunk egy elemet
	//2. ha nincs sx := abnorm, oszt csá
	//3. ha van, feldolgozzuk és sx := norm

	x>>dt.orszag;	//egy egyseget beolvastam, ez tortenetesen az orszagnev
	if(x.fail())	//ez az az eset, ha mar nem volt: azaz vege a file-nak
	{
		st = abnorm;
	}
	else			//most minden nagyon jo, johet a feldolgozasa a sornak!
	{
		st = norm;	//ott all az olvasofej az orszagnev utan, most jonnek tehat a varosok.
		/*
			megj.: ezt a "beolvasok egy sort", ezt nyugodtan irhattam volna az x>>dx.orszag helyere is
			es akkor a stringstreambol eloszor az orszagot olvastam volna ki itt ezen a ponton.
		*/
		string s;
		getline(x,s);	//itt a sorban mar nincs benne az orszagnev, hisz beolvastam mar
		stringstream ss(s);

		dt.varosok.resize(0);	//ez fontos, kulonben az osszes varost megorizne ami eddig volt

		Varos v;
		v.nev = "";	//osszegzes tetel
		//tehat most itt allunk az elso varosnal. ahhoz hogy megtudjuk van-e egyaltalan,
		//muszaj eloreolvasni!
		string sv;
		ss>>sv;
		while(!ss.fail())
		{
			int szam = atoi(sv.c_str());
			if(szam == 0 && sv != "0")	//ha nem volt szam
			{
				v.nev += (sv + " ");
			}
			else	//most vagyok az aktualis varos "vegen", a lakossagszamnal.
			{
				v.nev = v.nev.substr(0, v.nev.size()-1);	//lekapom az utolso szokozt, hogy szep legyen
				v.lakok = szam;
				dt.varosok.push_back(v);
				v.nev = "";		//mivel a v valtozo eletben marad (es a tombbe egy masolat kerul rola) ezert itt nullazni kell az osszegzest
			}
			ss>>sv;
		}
	}
}

Data Enor::Current() const
{
	return dt;
}

bool Enor::End() const
{
	return st == abnorm;
}
