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
		cout<<t.Current().nev<<" ";
		for(int i=0;i<(int)t.Current().befiz.size();++i)
			cout<<t.Current().befiz[i].datum<<" "<<t.Current().befiz[i].penz<<" ";
		cout<<endl;
	}*/

	int mennyibe = 0;
	int mennyikell = 0;
	bool van = false;
	Diak legkorabban;
	for(t.First();!t.End();t.Next())
	{
		mennyibe += osszeg(t.Current().befiz);	//osszegzes
		mennyikell += 13000;	//osszegzes; mert minden diaknak 13000-et kell...

		if(osszeg(t.Current().befiz) == 13000)	//feltmaxker; ez a "beta"
		{
			if(van)	//ez az "l"
			{
				if(legkorabban.befiz[legkorabban.befiz.size()-1].datum > t.Current().befiz[t.Current().befiz.size()-1].datum)
				{
					legkorabban = t.Current();
				}
				//tehat ha az eddigi legkorabbi diak utolso befizetese kesobbi, mint az aktualise, akkor az aktualis korabbi nala.
			}
			else
			{
				van = true;
				legkorabban = t.Current();
			}
		}
	}

	cout<<"Meg "<<mennyikell-mennyibe<<" lovetta hianyzik."<<endl;
	if(van)
		cout<<"A legkorabbi befizeto neve: "<<legkorabban.nev<<"."<<endl;
	else
		cout<<"Meg senki se fizette be."<<endl;

    return 0;
}

int osszeg(const vector<Par> &v)
{
	int s = 0;

	for(size_t i=0;i<v.size();++i)
		s += v[i].penz;

	return s;
}
