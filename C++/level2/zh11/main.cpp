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

	int befolyt = 0;
	int kellene = 0;
	t.First();
	Lakas elem = t.Current();				//maxkiv inic.
	kellene += t.Current().kkoltseg * 5;	//osszegzesek az elso elemre
	befolyt += osszeg(t.Current().befiz);
	for(t.Next();!t.End();t.Next())					//2. elemtol!
	{
		int ossz = osszeg(t.Current().befiz);	//FHV, mert ket helyen is hasznalom

		if(osszeg(elem.befiz) < ossz)				//maxkiv a 2. elemtol
			elem = t.Current();

		kellene += t.Current().kkoltseg * 5;		//osszegzesek dolgai a masodik elemtol
		befolyt += ossz;
	}
	cout<<"A kulonbozet a szukseges es befolyt penzek kozott: "<<kellene-befolyt<<" ft."<<endl;
	cout<<"Az egyik legtobb penzt befizeto lakas azonositoja: "<<elem.azon<<"."<<endl;

    return 0;
}

int osszeg(const vector<Par> &v)
{
	int s = 0;

	for(size_t i=0;i<v.size();++i)
		s += v[i].penz;

	return s;
}
