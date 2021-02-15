#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
	Enor t("be.txt");
	//ellenorzeskeppen
	/*for(t.First();!t.End();t.Next())
		cout<<t.Current().nev<<" "<<t.Current().ossz<<" "<<t.Current().lastdatum<<endl;*/

	bool van = false;	//teljes osszeget kifizeto
	Adat legelso;
	for(t.First();!t.End();t.Next())
	{
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

    return 0;
}
