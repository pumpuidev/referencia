#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
	Enor t("f.txt");
	/*for(t.First();!t.End();t.Next())		//ell. kiiras
	{
		cout<<t.Current().nev<<" "<<t.Current().vdb<<" "<<t.Current().ossz<<endl;
	}*/

	t.First();		//bejaras inditasa
	int s = 0;		//tetel inicializalasa
	if(!t.End())	//maxkiv elofeltetele
	{
		Orszag d = t.Current();		//FHV
		Orszag maxorszag = d;		//maxkiv inicializalasa
		s += d.ossz;	//osszegzes elso kore
		cout<<d.nev<<" "<<d.vdb<<endl;	//masik osszegzes elso kore
		for(t.Next();!t.End();t.Next())	//tobbi kor
		{
			d = t.Current();			//FHV
			if(maxorszag.ossz < d.ossz)	//maxkiv
				maxorszag = d;
			s += d.ossz;	//osszegzes
			cout<<d.nev<<" "<<d.vdb<<endl;	//masik osszegzes
		}
		cout<<s<<endl;			//osszegzes eredmenye
		cout<<maxorszag.nev<<endl;	//maxkiv eredmenye
	}
	else
		cout<<0<<endl;	//osszegzes eredmenye (a tobbi tetel meg ures stringet ad)

    return 0;
}
