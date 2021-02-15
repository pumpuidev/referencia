#include<iostream>
#include"enor.h"

using namespace std;

int main()
{
	Enor t("be.txt");
	//ellenorzeskeppen
	/*for(t.First();!t.End();t.Next())
	{
		cout<<t.Current().azon<<" "<<t.Current().osszbefiz;
		if(t.Current().befizette)
			cout<<" (befizette)"<<endl;
		else
			cout<<endl;
	}*/

	bool l = false;	//ezt most tenyleg linkerkent irom meg.
	Adat elem;
	for(t.First();!l && !t.End();t.Next())
	{
		cout<<t.Current().azon<<": "<<t.Current().osszbefiz<<" ft."<<endl;

		l = t.Current().befizette;
		elem = t.Current();
	}
	//ha nem volt talalat (l hamis) akkor ez vegigment.
	//ha volt, akkor most elemben benne van, tovabb is leptunk eggyel, de megallt a ciklus!!
	//ezert folytatni kell:
	for(;!t.End();t.Next())	//azert hagytam el az elejerol az olvasast, mert a linker tovabblepett mar a sajat ciklusa vegen!
	{
		cout<<t.Current().azon<<": "<<t.Current().osszbefiz<<" ft."<<endl;
	}

	if(l)
		cout<<elem.azon<<" befizette az eves dijat."<<endl;
	else
		cout<<"Senki se fizette be a teljes arat."<<endl;

    return 0;
}
