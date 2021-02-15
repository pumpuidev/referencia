#include "beolvasas.h"

using namespace std;

/*
	Egy karaktert ad vissza, ami "egyik"-kel vagy "masik"-kal azonos.
	Kezdetben kiirja az "uzenet"-et, majd addig olvassa be a karaktert, amig
	nem felel meg a fenti feltetelnek.
*/
char beolv_char(char egyik, char masik, const string uzenet)
{
	cout<<uzenet<<endl;

	char c;
	bool hiba;
	do
	{
		cin>>c;
		c = tolower(c);
		hiba = (c != egyik && c != masik);
		if(hiba)
		{
			cout<<"Nem jo, add meg ujra!"<<endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	while(hiba);

	return c;
}

/*
	Beolvassa a megadott k tombbe a korosztaly-hatarokat.
	Az adatforras valamint a beolvasas ismetelhetosege parameterkent
	megadhato.
*/
bool beolv_korosztalyok(vector<int> &k, istream &forras, bool ismet)
{
	if(forras.fail())
	{
		cout<<"Nem sikerult kapcsolodni az adatforrashoz. Sikertelen beolvasas!"<<endl;
		return false;
	}

	k.resize(0);	//mert hatha nem volt ures a tomb

	bool szinthiba;	//rossz adat van a forrasban
	bool szemhiba;	//az adatok egymashoz kepest levo viszonya miatt hiabasak
	bool folyt;		//folytatom-e a beolvasast
	int akt;		//aktualis beszurando elem
	do
	{
		if(ismet)	//csak ha nem automatikus beolvasasrol (fajl) van szo, akkor irogatok ki mindenfelet...
			cout<<"Add meg a kovetkezo korosztaly felso hatart!"<<endl;

		forras>>akt;
		szinthiba = (forras.fail() || akt < 0);
		szemhiba = (k.size() > 0 && k[(int)k.size()-1] >= akt);

		if(!szinthiba && !szemhiba)	//ha nem volt hiba...
		{
			k.push_back(akt);
			folyt = true;
		}
		else if(szinthiba)			//ha tipusaban helytelen adatot adott meg...
		{
			if(ismet)
			{
				cout<<"Nem termeszetes szam!"<<endl;
				forras.clear();
				forras.ignore(1000,'\n');
				char ujra = beolv_char('i','n',"Akarsz ujra probalkozni? (i/n)");
				folyt = (ujra == 'i');
			}
			else
				folyt = false;

		}
		else if(szemhiba)			//ha nem novekvo sorban adott meg adatokat...
		{
			if(ismet)
			{
				cout<<"Nem jo, a korosztalyhatarok szigoruan monoton nojenek!"<<endl;
				forras.clear();
				forras.ignore(1000,'\n');
				char ujra = beolv_char('i','n',"Akarsz ujra probalkozni? (i/n)");
				folyt = (ujra == 'i');
			}
			else
				folyt = false;
		}
	}
	while(folyt);

	if(ismet || szinthiba)	//az "ismet" azt jelenti, hogy ha akart, javithatott, ezert ilyenkor biztosan sikeres volt
	{						//a beolvasas. ha ez hamis, akkor csak akkor volt sikeres ha az elso hibasig olvastunk
		cout<<"Sikeresen beolvastam "<<k.size()<<" db korosztaly-hatart, azaz "<<k.size()+1<<" db korosztalyt!"<<endl;
		return true;
	}
	else
	{
		cout<<"Hibas adatsorozat, a beolvasas sikertelen!"<<endl;
		return false;
	}
}

/*
	Beolvassa o-ba az osztalyzatokat, megpedig ugy, hogy a k alapjan megadott korosztalyok
	vektorainak vegebe irjuk mindig be az aktualisan megadott osztalyzatot.
	A forrast es az ismetelhetoseget itt is parameterkent adhatjuk meg.
*/
bool beolv_osztalyzatok(vector<vector<int> > &o, const vector<int> &k, istream &forras, bool ismet)
{
	if(forras.fail())
	{
		cout<<"Nem sikerult kapcsolodni az adatforrashoz. Sikertelen beolvasas!"<<endl;
		return false;
	}

	o.resize(0);
	o.resize((int)k.size() + 1);	//ennyi kategoria (korosztaly) van

	int kor;		//az aktualisan beolvasott eletkor
	int oszt;		//az aktualisan beolvasott osztalyzat
	bool hiba;		//hibas volt-e
	bool folyt;		//akarjuk-e folytatni
	do
	{
		if(ismet)
			cout<<"Add meg a kovetkezo ertekelo korat!"<<endl;

		forras>>kor;
		hiba = forras.fail() || kor < 0;	//legalabb 0 eves mindenki

		if(hiba)
		{
			if(ismet)
			{
				cout<<"Nem jo, nemnegativ egesz szamot varok!"<<endl;
				forras.clear();
				forras.ignore(1000,'\n');
				char ujra = beolv_char('i','n',"Akarsz ujra probalkozni? (i/n)");
				folyt = (ujra == 'i');
			}
			else
				folyt = false;
		}
		else
		{
			if(ismet)
				cout<<"Add meg az aktualis ertekelo osztalyzatat!"<<endl;

			forras>>oszt;
			hiba = forras.fail() || oszt < 1 || oszt > 5;	//[1..5]-beli ertekelesek legyenek!

			if(hiba)
			{
				if(ismet)
				{
					cout<<"Nem jo, 1-tol 5-ig varok egy erteket!"<<endl;
					forras.clear();
					forras.ignore(1000,'\n');
					char ujra = beolv_char('i','n',"Akarsz ujra probalkozni? (i/n)");
					folyt = (ujra == 'i');
				}
				else
					folyt = false;
			}
			else
			{
				//beszurjuk az ertekelest a megfelelo tombbe:
				//linkerrel megkeressuk a korosztalyok kozott azt, aki mar nagyobb v. egyenlo nala,
				//az ELSO ilyet (hiszen a linker azt talalja meg), es annak a kategoriajaba fog esni!
				//ha ures, akkor egy db kategoria van.
				int ind = 0;	//ha be se lep, mert 0 a merete, akkor marad 0...
				bool l = false;
				for(int i=0;!l && i<(int)k.size();++i)
				{
					ind = i;
					l = k[i] >= kor;
				}

				//ha senki se volt nagyobb nala... akkor az utolso kategoriaba esik
				//(osszesen k.size() + 1 kategoria van ugyebar
				if(l)
					o[ind].push_back(oszt);
				else
					o[(int)o.size()-1].push_back(oszt);

				folyt = true;	//sikeresen beszurtam, johet a kovetkezo!
			}
		}
	}
	while(folyt);

	int c = 0;
	for(int i=0;i<(int)o.size();++i)
		c += o[i].size();

	cout<<"Sikeresen beolvastam "<<c<<" db ertelekelest!"<<endl;

	return true;
}

/*
	k-ban adottak a korosztaly felso hatarok,
	ez alapjan kiirja a korosztalokyat intervallumkent jelolve.
	Az utolso elem utan van meg az onala ideosebbek korosztalya, azaz
	az [utolso+1 .. vegtelen) is!
*/
void kiir_korosztalyok(const vector<int> &k)
{
	if(k.size() == 0)					//ha ures a tomb, mindenki egy korosztalyba tartozik
		cout<<"[0..+vegtelen)"<<endl;
	else
	{
		int eleje = 0;
		for(int i=0;i<(int)k.size();++i)
		{
			cout<<"["<<eleje<<".."<<k[i]<<"]"<<endl;
			eleje = k[i] + 1;			//a kovetkezo korosztaly a mostani felso hataranal eggyel idosebbtol indul...
		}
		cout<<"["<<eleje<<".."<<"+vegtelen)"<<endl;		//az utolso korosztaly
	}
}

/*
	Kiirjuk az o kesztyumatrix minden soranak osszes elemeit (jegyeket) szokozokkel elvalasztva.
*/
void kiir_osztalyzatok(const vector<vector<int> > &o)
{
	for(int i=0;i<(int)o.size();++i)
	{
		cout<<i+1<<". korosztaly szavazatai:"<<endl;
		cout<<"\t";
		if(o[i].size() == 0)
			cout<<"nincs"<<endl;
		else
		{
			for(int j=0;j<(int)o[i].size();++j)
				cout<<o[i][j]<<" ";
			cout<<endl;
		}
	}
}
