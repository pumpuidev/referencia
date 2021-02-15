#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
	Enor t("be.txt");
	//ellenorzeskeppen
	/*for(t.First();!t.End();t.Next())
		cout<<t.Current().nev<<" "<<t.Current().ossz<<" "<<t.Current().reszletek<<" "<<t.Current().lastdatum<<endl;*/

	//"ugye nincs olyan tanulo, aki ne legalabb ket reszletben fizetett volna?"
	//atirasa:
	//nem letezik olyan x, hogy nem(x.reszletek >= 2)
	//azaz:
	//minden x olyan, hogy nem(nem(x.reszletek >= 2))
	//azaz:
	//minden x olyan, hogy x.reszletek >= 2
	//magyarul:
	//"ugye minden tanulo legalabb ket reszletben fizetett?"

	bool van = false;	//teljes osszeget kifizeto
	Adat legelso;
	bool minden = true;	//opt. linker atirasa osszegzeses alakba!
	for(t.First();!t.End();t.Next())
	{
		minden = minden && t.Current().reszletek >= 2;

		cout<<t.Current().nev<<": "<<t.Current().ossz<<" ft."<<endl;	//osszegzes

		if(t.Current().lastdatum != "")		//feltmaxker
		{
			if(van)
			{
				if(legelso.lastdatum > t.Current().lastdatum)
				{
					legelso = t.Current();
				}
			}
			else
			{
				van = true;
				legelso = t.Current();
			}
		}
	}

	if(van)
		cout<<"A legelso befizeto neve: "<<legelso.nev<<"."<<endl;
	else
		cout<<"Meg senki se fizette be teljesen."<<endl;

	if(minden)
		cout<<"Ugye nincs."<<endl;
	else
		cout<<"De van. Hogy a macska rugja meg!"<<endl;

    return 0;
}
