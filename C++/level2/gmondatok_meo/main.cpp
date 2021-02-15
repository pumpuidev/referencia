#include <iostream>
#include <fstream>
#include <sstream>
#include "enor_mondat.h"
#include "enor_mondathossz.h"

using namespace std;

int mondathossz(string mondat);

int main()
{
	//1. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondatok felosorolasaval)
	Enor_mondat t1("be.txt");
	int c1 = 0;
	for(t1.First();!t1.End();t1.Next())	//szamlalas tetel + mondatok felsorolasa
	{
		//cout<<t1.Current()<<endl; //eleg csunyan sorolja fel, mert az uj sorokat meg a szokozoket nem ugorja at
		if(mondathossz(t1.Current())>20)
			++c1;
		//cout<<mondathossz(t1.Current())<<endl;
	}
	cout<<c1<<endl;

	//2. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondathosszak felosorolasaval)
	Enor_mondathossz t2("be.txt");
	int c2 = 0;
	for(t2.First();!t2.End();t2.Next())	//szamlalas tetel + mondathosszok felsorolasa
	{
		//cout<<t2.Current()<<endl;
		if(t2.Current()>20)
			++c2;
	}
	cout<<c2<<endl;

    return 0;
}

int mondathossz(string mondat)
{
	//logikus lenne, hogy mivel a mondat szavakbol all, ezt most daraboljuk fel szavakra, es adjuk ossze a hosszaikat, de ez meg egyszerubb:
	stringstream ss(mondat);
	//szamlalas tetel
	int c = 0;
	char sv;
	ss>>sv;				//WS-eket eldobja
	while(!ss.fail())
	{
		if(sv != ',')	//'.' nincs benne, mert az volt a hatarolojel
			++c;
		ss>>sv;
	}
	return c;
}
