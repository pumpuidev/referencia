#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct Fagyi
{
	string nev;
	int gomboc;
};

bool beolvas(vector<Fagyi> &t);
bool mindenkiegyszer(const vector<Fagyi> &t);
bool egyszer(const vector<Fagyi> &t, size_t i);
void kiir(const vector<Fagyi> &t);
string maxkiv(const vector<Fagyi> &t);
int tobbgomboc(const vector<Fagyi> &t, size_t i);

int main()
{
	vector<Fagyi> t;
	if(beolvas(t))
    {
        kiir(t);
        cout<<"A keresett diak: "<<maxkiv(t)<<endl;
    }
	return 0;
}

bool beolvas(vector<Fagyi> &t)
{
	ifstream ifs("f8.txt");
	if(ifs.fail())	//hiba, ha nincs file
	{
		cerr<<"Hibas vagy nem letezo fajl!"<<endl;
		return false;
	}

	bool vege = false;
	do
	{
		Fagyi akt;
		ifs>>akt.nev;
		vege = ifs.fail();	//gyakorlatilag akkor nem tudunk mar olvasni (stringet) ha vege a fajlnak
		if(!vege)
		{
			ifs>>akt.gomboc;

			if(ifs.fail() || akt.gomboc < 0)//ha mar olvastunk nevet, akkor ha nem tartozik hozza gomboc (fail), vagy nem szam (fail), vagy negativ (< 0),
            {                               //akkor az mind-mind hiba!
                cerr<<"A beolvasas sikertelen, mert hulyeseg ez a fajl sajnos."<<endl;
                ifs.close();
                return false;
            }
            t.push_back(akt);
		}
	}
	while(!vege);

	ifs.close();

	if(t.size() < 1)	//hiba, ha nincs eleg fagyit nyalo jobarat
	{
		cerr<<"Tul keves diak van :("<<endl;
		return false;
	}

	if(!mindenkiegyszer(t))	//hiba, ha valaki tobbszor is nyalt
	{
		cerr<<"Valamelyik tul falank volt, pokolra jut :'("<<endl;
		return false;
	}
	return true;
}

bool mindenkiegyszer(const vector<Fagyi> &t)   //for alakban (lehet while is)
{
	bool l = true;
	for(size_t i = 1;l && i<t.size();++i)
		l = egyszer(t,i);
	return l;
}

bool egyszer(const vector<Fagyi> &t, size_t i)  //while alakban (lehet for is)
{
	bool l = true;
	size_t j = 0;
	while(l && j<i) //itt mar egyszer mind i-bol, mind j-bol kivontunk egyet (mivel indexek), ezert nem kell meg egyszer!
	{
		l = t[i].nev != t[j].nev;
		++j;
	}
	return l;
}

void kiir(const vector<Fagyi> &t)
{
    for(size_t i=0;i<t.size();++i)
        cout<<t[i].nev<<"\t\t"<<t[i].gomboc<<endl;
    cout<<endl;
}

string maxkiv(const vector<Fagyi> &t)   //ef: n>0
{
    size_t max = tobbgomboc(t,0);
	size_t ind = 0;
	for(size_t i=1;i<t.size();++i)
	{
		int m = tobbgomboc(t,i);	//FHV
		if(m > max)
		{
			max = m;
			ind = i;
		}
	}
	return t[ind].nev;
}

int tobbgomboc(const vector<Fagyi> &t, size_t i)
{
	size_t c = 0;
	for(size_t j=0;j<i;++j)
		if(t[j].gomboc < t[i].gomboc)
			++c;
	return c;
}
