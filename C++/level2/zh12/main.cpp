#include<iostream>
#include"enor.h"

using namespace std;

int osszeg(const vector<Par> &v);

int main()
{
	Enor t("be.txt");
	//ellenorzeskeppen
	/*for(t.First();!t.End();t.Next())
	{
		cout<<t.Current().azon<<" "<<t.Current().kkoltseg<<" ";
		for(int i=0;i<(int)t.Current().befiz.size();++i)
			cout<<t.Current().befiz[i].datum<<" "<<t.Current().befiz[i].penz<<" ";
		cout<<endl;
	}*/

	bool minden = true;		//"optimista linker" helyett osszegzes alaku tetel
	int befolyt = 0;
	int kellene = 0;
	t.First();
	minden = minden && (osszeg(t.Current().befiz) == t.Current().kkoltseg * 5);	//vizsgalat az elso elemre...
	Lakas elem = t.Current();
	kellene += t.Current().kkoltseg * 5;
	befolyt += osszeg(t.Current().befiz);
	for(t.Next();!t.End();t.Next())
	{
		int ossz = osszeg(t.Current().befiz);

		minden = minden && (ossz == t.Current().kkoltseg * 5);	//vizsgalat a tobbi elemre

		if(osszeg(elem.befiz) < ossz)
			elem = t.Current();

		kellene += t.Current().kkoltseg * 5;
		befolyt += ossz;
	}
	cout<<"A kulonbozet a szukseges es befolyt penzek kozott: "<<kellene-befolyt<<" ft."<<endl;
	cout<<"Az egyik legtobb penzt befizeto lakas azonositoja: "<<elem.azon<<"."<<endl;
	if(minden)
		cout<<"Minden lakas befizette, amit be kell"<<endl;
	else
		cout<<"Van olyan lakas, ami nem fizetett be valamit"<<endl;
	//egyebkent ehhez nem is kellett volna kulon tetel,
	//mert ha a "kellene-befolyt" = 0, akkor befizettek, ha nem, nem.

    return 0;
}

int osszeg(const vector<Par> &v)
{
	int s = 0;

	for(size_t i=0;i<v.size();++i)
		s += v[i].penz;

	return s;
}
