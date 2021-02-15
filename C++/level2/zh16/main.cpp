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
			cout<<" (befizette)";
		if(t.Current().jolfizetett)
			cout<<" (volt jol fizetett honapja)";
		cout<<endl;
	}*/

	//"ugye nincs olyan lakas ami soha nem a megfelelo osszeget fizette volna"
	//atirva:
	//nincs x: (nincs y eleme x.befizetések: y = x.kkoltseg)
	//azaz:
	//minden x: NEM(nincs y eleme x.befizetések: y = x.kkoltseg)
	//azaz:
	//minden x: (van y eleme x.befizetések: y = x.kkoltseg)
	//magyarul: "ugye minden lakas olyan, hogy legalább egyszer jól fizetett?"
	//ezt a tételt megint összegzés alakban csinálom meg, mert egyszerubb

	bool l = false;	//pessz linker
	bool minden = true;	//opt linker (az otosert levo feladat)
	Adat elem;
	for(t.First();!l && !t.End();t.Next())
	{
		cout<<t.Current().azon<<": "<<t.Current().osszbefiz<<" ft."<<endl;

		l = t.Current().befizette;
		elem = t.Current();

		minden = minden && t.Current().jolfizetett;
	}
	//ha nem volt talalat (l hamis) akkor ez vegigment.
	//ha volt, akkor most elemben benne van, tovabb is leptunk eggyel, de megallt a ciklus!!
	//ezert folytatni kell:
	for(;!t.End();t.Next())	//azert hagytam el az elejerol az olvasast, mert a pessz. linker tovabblepett mar a sajat ciklusa vegen!
	{
		cout<<t.Current().azon<<": "<<t.Current().osszbefiz<<" ft."<<endl;

		minden = minden && t.Current().jolfizetett;	//ez meg az opt. linker
	}

	if(l)
		cout<<elem.azon<<" befizette az eves dijat."<<endl;
	else
		cout<<"Senki se fizette be a teljes arat."<<endl;

	if(minden)
		cout<<"Minden lakas legalabb egy honapban ertelmesen fizetett."<<endl;
	else
		cout<<"Van olyan lakas, amelyik sose annyit fizetett, mint kellett volna."<<endl;

    return 0;
}
