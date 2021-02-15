#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void beolv_g(vector<int> &v);
void beolv_g2(vector<int> &v);
void beolv_f(vector<int> &v);
void beolv_f2(vector<int> &v);
void kiir(const vector<int> &v);

size_t maxkiv(const vector<int> &v);			    //kulso tetel, ef: v.size()>0; inddel ter vissza
size_t szamlalas(const vector<int> &v, size_t i);	//belso tetel

int main()
{
	vector<int> v;
	beolv_g(v);
	//beolv_g2(v);
	//beolv_f(v);
	//beolv_f2(v);
	cout<<"A beolvasott elemek:"<<endl;
	kiir(v);
	cout<<endl;
    if(v.empty())
		cout<<"A tomb ures"<<endl;	//elofeltetel serulest nem feltetlenul csak a beolvasasban lehet vegezni
									//a cel csupan annyi: ne fusson le a tetel, ha nem teljesul az ef.
	else
		cout<<"A(z) "<<maxkiv(v) + 1<<". elem elott van a legtobb nala nagyobb"<<endl;  //a kodban mindig 0-tol indexelunk. mindig a beolvasas es a kiiras legyen az a pont ahol megtesszuk az [1..n] intervallumra valo atvaltast

	return 0;
}

void beolv_g(vector<int> &v)
{
	cout<<"Ird be a szamokat! Az elso helytelennel kilepek."<<endl;
	v.resize(0);
	int n;
	while(cin>>n && n % 2 == 0)
		v.push_back(n);
	cout<<"Hibas ertek, beolvasas vege"<<endl;
}

void beolv_f(vector<int> &v)
{
	string fnev;
	ifstream ifs;
	cout<<"Add meg a file nevet!"<<endl;
	cin>>fnev;
	ifs.open(fnev.c_str());	//vagy eleve igy deklaralom: ifstream ifs(fnev.c_str());

	v.resize(0);
	int n;
	while(ifs>>n && n % 2 == 0)
		v.push_back(n);
	ifs.close();
}

void beolv_g2(vector<int> &v)
{
	cout<<"Ird be a szamokat! Az elso helytelennel kilepek."<<endl;
	v.resize(0);
	int n;
	bool hiba;

	do
	{
		cin>>n;
		hiba = cin.fail() || n % 2 != 0;
		if(hiba)
		{
			cin.ignore(1000,'\n');
			//vagy: string str; getline(cin,str);
			cin.clear();
			cout<<"Hibas ertek, beolvasas vege"<<endl;
		}
		else
			v.push_back(n);
	}
	while(!hiba);
}

void beolv_f2(vector<int> &v)
{
	string fnev;
	ifstream ifs;
	cout<<"Add meg a file nevet!"<<endl;
	cin>>fnev;
	ifs.open(fnev.c_str());

	v.resize(0);

	int n;
	bool hiba;
	do
	{
		ifs>>n;
		hiba = ifs.fail() || n % 2 != 0;
		if(!hiba)
			v.push_back(n);
	}
	while(!hiba);

	ifs.close();
}

void kiir(const vector<int> &v)
{
	for(size_t i=0;i<v.size();++i)
		cout<<v[i]<<" ";
}

size_t maxkiv(const vector<int> &v)	//konstans, mert itt nem modositok rajta
{
    size_t ind = 0;
    size_t max = 0;	//szamlalas(v,0) erteke garantaltan 0, hiszen az elso elem elott nincs senki...
    for(size_t i=1;i<v.size();++i)
    {
        size_t c = szamlalas(v,i);		//FHV
        if(max < c)
		{
			ind = i;
            max = c;
		}
    }
    return ind;
}

size_t szamlalas(const vector<int> &v, size_t i)
{
	size_t c = 0;           //a tipus azert ez, mert c az indexeken megy vegig
	for(size_t j=0;j<i;++j)	//j<i ekvivalens j<=i-1
		if(v[j] > v[i])
			++c;
	return c;
}
