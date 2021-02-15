#include<iostream>
#include<vector>
#include"enor_interval.h"
#include"enor_tomb.h"

using namespace std;

int szamlalas_interval(vector<int> v);			//számlálás tétel intervallum felsorolásával
int szamlalas_vect(vector<int> v);				//számlálás tétel vektor felsorolásával
bool pozitiv(vector<int> v, size_t i);			//vektor i-edik eleme pozitív-e (ez egy béta(i) az intervallumoshoz)
bool pozitiv(int e);							//szám pozitív-e (ez egy béta(e) a vektoroshoz, mert ott a számot magát, nem az indexet soroljuk fel)
int abs(int e);									//abszolutérték (vektor felsorolásához)
int szamlalas(Enor_interval &t, vector<int> v);	//feladat: külön felsoroló objektummal megvalósított intervallumbejárós számlálás
int szamlalas(Enor_tomb &t);					//feladat: külön felsoroló objektummal megvalósított vektorbejárós számlálás
int maxkiv(Enor_tomb &t);						//feladat: külön felsoroló objektummal megvalósított vektorbejárós maxkiv

//feladat: a két bejáró osztály
//feladat: egy maxkiv és számlálás "párhuzamosan" a foprogramba

int main()
{
	vector<int> v;		//a bemenet...
	v.push_back(0);
	v.push_back(3);
	v.push_back(-1);
	v.push_back(-5);
	v.push_back(5);
	v.push_back(-4);
	v.push_back(2);
	v.push_back(-9);
	v.push_back(-4);

	for(size_t i=0;i<v.size();++i)	//ellenorzo kiiras, amugy ez egy osszegzes tetel vegul is
		cout<<v[i]<<" ";
	cout<<endl;

	Enor_interval ti(0,v.size()-1);
	for(ti.First();!ti.End();ti.Next())	//intervallum felsorolo ellenorzese
		cout<<ti.Current()<<" ";
	cout<<endl;

	Enor_tomb tv(v);
	for(tv.First();!tv.End();tv.Next())	//vektor felsorolo ellenorzese
		cout<<tv.Current()<<" ";
	cout<<endl<<endl;

	cout<<szamlalas_interval(v)<<endl;	//a megírt, sima számlálások kipróbálása
	cout<<szamlalas_vect(v)<<endl;

	Enor_interval t1(0,v.size()-1);		//intervallumfelsoroló - [0..n-1]-et kell neki felsorolnia, a vektorról "nem is tud"!
	cout<<szamlalas(t1,v)<<endl;		//cserébe itt meg kell adni a vektort.

	Enor_tomb t2(v);					//vektorfelsoroló
	cout<<szamlalas(t2)<<endl;			//most már nem kell megadni, csak a felsorolót - "cserébe" nem tudunk indexet lekérni

	Enor_tomb t3(v);					//azért csinálok minden tételhez új felsoroló objektumot, mert majd a fájlosnál
	cout<<maxkiv(t3)<<endl;				//nem lesz garantálva, hogy újraindul a fájl olvasás, egy használt felsorolónál.
										//itt speciel a first mindig 0-zza i-t, tehat ilyen gond nem lenne.
	//maxkiv és számlálás együtt:
	Enor_tomb t(v);						//felsoroló
	int c = 0;							//inicializálás
	t.First();							//felsorolás indítása
	if(pozitiv(t.Current()))			//külön az elso elemre elvegezzuk a szamlalas ciklusmagjat...
			++c;
	int max = abs(t.Current());			//...ugyanis a maxkiv-re külön KELL kezelni az elso elemet, ezert voltunk kenytelenek a szamlalasnal is
	for(t.Next();!t.End();t.Next())		//ne feledkezzunk meg az elso nextrol! ez loki a 2. tombelemre a felsorolót
	{
		if(pozitiv(t.Current()))		//számlálás ciklusmagja
			++c;
		if(max < abs(t.Current()))		//maxkiv ciklusmagja
			max = abs(t.Current());
	}

	cout<<c<<" "<<max<<endl;			//eredmények

    return 0;
}

int szamlalas_interval(vector<int> v)	//lehet forral is
{
	int c = 0;

	size_t i = 0;
	while(i<v.size())
	{
		if(pozitiv(v,i))	//beta(i)
				++c;
		++i;
	}

	return c;
}

int szamlalas_vect(vector<int> v)	//ezt is lehet persze forral is
{
	int c = 0;

	size_t i = 0;
	while(i<v.size())
	{
		if(pozitiv(v[i]))	//beta(e)
				++c;
		++i;
	}

	return c;
}

int abs(int e)
{
	return e > 0 ? e : -e;
}

bool pozitiv(vector<int> v, size_t i)
{
	return v[i] > 0;
}

bool pozitiv(int e)
{
	return e > 0;
}

/*int szamlalas_absztr(Enor &t)
{
	int c = 0;

	t.First();
	while(!t.End())
	{
		if(pozitiv(t.Current()))
				++c;
		t.Next();
	}

	return c;
}

int szamlalas_absztr_forral(Enor &t)		//csak mert ugyanaz, de igy rovidebb
{
	int c = 0;

	for(t.First();!t.End();t.Next())
		if(pozitiv(t.Current()))
				++c;

	return c;
}*/

int szamlalas(Enor_interval &t, vector<int> v)
{
	int c = 0;

	for(t.First();!t.End();t.Next())
		if(pozitiv(v,t.Current()))
				++c;

	return c;
}

int szamlalas(Enor_tomb &t)
{
	int c = 0;

	for(t.First();!t.End();t.Next())
		if(pozitiv(t.Current()))
				++c;

	return c;
}

int maxkiv(Enor_tomb &t)
{
	t.First();
	int max = abs(t.Current());
	for(t.Next();!t.End();t.Next())
	{
		if(abs(t.Current()) > max)
			max = abs(t.Current());
	}

	return max;
}
