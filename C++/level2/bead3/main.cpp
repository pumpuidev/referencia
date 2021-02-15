#include<iostream>
#include"enor.h"

using namespace std;

int osszlakossag(const Data &d);

int main()
{
	Enor t("f.txt");
	/*for(t.First();!t.End();t.Next())		//ell. kiiras
	{
		cout<<t.Current().orszag<<" ";
		for(int i=0;i<t.Current().varosok.size();++i)
			cout<<t.Current().varosok[i].nev<<" "<<t.Current().varosok[i].lakok<<" ";
		cout<<endl;
	}*/

	t.First();		//bejaras inditasa
	int s = 0;		//tetel inicializalasa
	if(!t.End())	//maxkiv elofeltetele
	{
		Data d = t.Current();	//FHV
		Data maxorszag = d;		//maxkiv inicializalasa
		s += osszlakossag(d);	//osszegzes elso kore
		cout<<d.orszag<<" "<<d.varosok.size()<<endl;	//masik osszegzes elso kore
		for(t.Next();!t.End();t.Next())	//tobbi kor
		{
			d = t.Current();			//FHV
			int ol = osszlakossag(d);	//FHV

			if(osszlakossag(maxorszag) < ol)	//maxkiv
				maxorszag = d;
			s += ol;	//osszegzes
			cout<<d.orszag<<" "<<d.varosok.size()<<endl;	//masik osszegzes
		}
		cout<<(s*1000)<<endl;			//osszegzes eredmenye
		cout<<maxorszag.orszag<<endl;	//maxkiv eredmenye
	}
	else
		cout<<0<<endl;	//osszegzes eredmenye (a tobbi tetel meg ures stringet ad)

    return 0;
}

int osszlakossag(const Data &d)	//osszegzes tetel
{
	int s = 0;

	for(size_t i=0;i<d.varosok.size();++i)
		s += d.varosok[i].lakok;

	return s;
}
