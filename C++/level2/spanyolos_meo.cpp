#include<fstream>
#include<iostream>
#include<sstream>	//egy sor kesobbi feldolgozasahoz
#include<cstdlib>	//atoi-hez
#include<vector>

using namespace std;

const string FAJLNEV = "spanyolok.txt";

struct Spanyol;

bool beolvas(vector<Spanyol> &v);
void kiir(const vector<Spanyol> &v);
int leghosszabbNevuKora(const vector<Spanyol> &v);
size_t nevHossz(const Spanyol &s);

struct Spanyol
{
    int kor;
    string nev;
};

int main()
{
	vector<Spanyol> losLocos;

	if(beolvas(losLocos))
    {
        kiir(losLocos);
        if(losLocos.size().empty())
		    cerr<<"Legalabb egy spanyol kell a max. kiv. elofeltetele miatt!"<<endl;
        else
            cout<<"A leghosszabb nevu spanyol kora: "<<leghosszabbNevuKora(losLocos)<<" ev."<<endl;
    }
    else
        cerr<<"Hibas file"<<endl;

    return 0;
}

bool beolvas(vector<Spanyol> &losLocos)
{
    ifstream ifs(FAJLNEV.c_str());
    if(ifs.fail())
	{
		cerr<<"Nincs ilyen file."<<endl;
		return false;
	}

    string sor;						//segedvaltozo egy sorhoz
    while(getline(ifs,sor))			//amig nem dob a getline-olas fail()-t...
    {
        Spanyol elLoco;				//majd ezt illesztjuk be - ha mar beolvastunk
        elLoco.nev = "";
        //cout<<sor<<"|";			//a getline az elso \n-ig (de azt mar nem beleertve) olvasott be
        stringstream ss(sor);		//most erre raallitunk egy string folyamot
        string sv,sv2;
        ss>>sv>>sv2;				//es abbol kiolvassuk a sor szokozokkel v. tab. jelekkel elvalasztott szavait

        if(ifs.fail())				//ha hibas volt, akkor a sorban nem volt legalabb ket szo (a masodik a kor), ez hiba
		{
			cerr<<"Rossz az egyik spanyolra vonatkozo adat."<<endl;
			ifs.close();
			return false;
		}

        while(!ss.fail())			//ha nem volt hibas, akkor sikerult ketto darabot is olvasni
        {
            elLoco.nev += sv;		//most hozzarakom (osszegzes tetel) az elso beolvasott stringet a nevhez,
            sv = sv2;				//majd a masodik lesz az "aktualis"
            ss>>sv2;				//es tovabbolvasom a masodikat...
        }
		//a fenti while-lal ekvivalens:
		/*
			elLoco.nev += sv;
			sv = sv2;
			while(ss>>sv2)	//olvas es egyben ellenorzi is a sikeresseget
			{
				elLoco.nev += sv;
				sv = sv2;
			}
		*/
		
        elLoco.kor = atoi(sv.c_str());	//es akkor lepunk ki, amikor ez a tovabbolvasas failt okozott, azaz vege lett a sornak
        //ekkor sv2-ben mar hulyeseg van, sv-ben pedig a sor utolso eleme, ami egy szam.

        if((elLoco.kor == 0 && sv != "0") || elLoco.kor < 0)	//ha megse jo szam...
		{
			cerr<<"Nem termeszetes szam a spanyol kora!"<<endl;
			ifs.close();
			return false;
		}

        losLocos.push_back(elLoco);
        //cout<<elLoco.nev<<"||"<<elLoco.kor<<endl;
    }

    ifs.close();
    return true;	//itt visszaterhetnek !losLocos.empty();-vel is, mivel ez a tetel feltetele
}					//de epp ezert - mivel maga a beolvasas vegulis ertelmes ures eseten is - itt meg elengedem, es a tetelnel ellenorzom
// ennek akkor lenne elonye, ha lenne ugyanerre a bemenetre mas tetel IS, aminek nem ef-e az, hogy nem ures a tomb

void kiir(const vector<Spanyol> &v)
{
    for(size_t i=0;i<v.size();++i)
        cout<<v[i].nev<<" ("<<v[i].kor<<")"<<endl;
}

int leghosszabbNevuKora(const vector<Spanyol> &v) //ef: v.size > 0
{
	//osszetett fv elso fele egy maxkiv:
    size_t max = nevHossz(v[0]);
    size_t ind = 0;
    for(size_t i=1;i<v.size();++i)
    {
    	size_t meret = nevHossz(v[i]);	//FHV
        if(meret > max)
        {
            ind  = i;
            max = meret;
        }
    }

    return v[ind].kor;	//osszetett fv masodik fele
}

size_t nevHossz(const Spanyol &s)
{
    return s.nev.size();
}
