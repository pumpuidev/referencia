#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdlib>

using namespace std;

//Tesztesetek:
//f0.txt - hibas fajl - nem letezik
//f1.txt - ures
//f2.txt - egy csoport, egy hallgato
//f3.txt - egy csoport, tobb hallgato
//f4.txt - tobb csoport, tobb hallgato; elsoben van a legjobb
//f5.txt - hibas fajl - ures csoport
//f6.txt - hibas fajl - rossz formatumu neptun-kod
//f7.txt - hibas fajl - rossz formatumu jegy
//f8.txt - hibas fajl - tul magas jegy (alacsonyra nem erdemes, mert az mar eleve sok karakter lenne)
//f9.txt - van bukos csoport, de tul kicsi letszamu; utolsoban van a legjobb
//f10.txt - csak bukos csoport van, de kicsi letszamu
//f11.txt - van eleg nagy letszamu bukos csoport

const string FILENEV = "f1.txt";

struct Hallgato
{
    string neptun;
    int jegy;
};

vector<string> tanarokatBeolvas();
bool csoportokatBeolvas(vector<vector<Hallgato> > &csoportok);
void csoportokatKiir(const vector<vector<Hallgato> > &csoportok);
void elsoFeladat(const vector<vector<Hallgato> > &csoportok);
bool voltBukoCsoport(const vector<vector<Hallgato> > &csoportok);
bool mindenkiBukott(const vector<Hallgato> &csoport);
void masodikFeladat(const vector<vector<Hallgato> > &csoportok, const vector<string> &tanarok);
string legjobbCsoportTanara(const vector<vector<Hallgato> > &csoport, const vector<string> &tanarok);
int legjobbJegy(const vector<Hallgato> &csoport);

int main()
{
    vector<string> tanarok = tanarokatBeolvas();
    vector<vector<Hallgato> > csoportok;
    if(csoportokatBeolvas(csoportok))
    {
        cout<<"Beolvasott csoportok:"<<endl;
        csoportokatKiir(csoportok);
        cout<<endl;
        cout<<"1. feladat:"<<endl;
        elsoFeladat(csoportok);
        cout<<"2. feladat:"<<endl;
        masodikFeladat(csoportok, tanarok);
    }
    else
    {
        cout<<"Nem sikerult a csoportokat beolvasni."<<endl;
    }
    return 0;
}

vector<string> tanarokatBeolvas()
{
    //Ez most el lett intezve ennyivel, ide lehetne kesziteni egy fajlbol vagy billentyuzetrol beolvasast
    //A funkcio tesztelesehez ez teljesen jo
    vector<string> tanarok;
    tanarok.push_back("Robi");
    tanarok.push_back("Tibi");
    tanarok.push_back("Balazs");
    tanarok.push_back("Andras");
    return tanarok;
}

bool csoportokatBeolvas(vector<vector<Hallgato> > &csoportok)
{
    ifstream ifs(FILENEV.c_str());
    if(ifs.fail())
    {
        return false;
    }

    string csoport;
    while(getline(ifs,csoport)) //Egy sor - egy csoport
    {
        if("" == csoport)   //Ures csoport nem megengedett
        {
            ifs.close();
            return false;
        }

        csoportok.resize(csoportok.size() + 1); //Ezzel beszurom a (kezdezben ures) csoportot

        stringstream ss(csoport);
        string hallgato;
        while(getline(ss,hallgato,' ')) //Hallgatok adatai egymastol szokozzel vannak elvalasztva...
        {
            if(8 != hallgato.size())    //Neptun-kod: 6 karakter + vesszo + jegy (ami garantaltan egy karakter)
            {
                ifs.close();
                return false;
            }

            Hallgato h;
            h.neptun = hallgato.substr(0,6);    //0-tol 6 hosszan, azaz az elso 6 karakter
            if(!isdigit(hallgato[7]))   //ha nem szam az utolso KARAKTER
            {
                ifs.close();
                return false;
            }
            h.jegy = atoi(hallgato.substr(7).c_str());  //Csinaljunk szamot az utolso karakterbol allo STRINGbol
            if(h.jegy < 0 || h.jegy > 5)    //Ha nem [0..5]-beli (bar negativ nem is lehet, ha egy karakteres volt)
            {
                ifs.close();
                return false;
            }

            csoportok[csoportok.size() - 1].push_back(h);   //Az aktualisan utolso csoportba beszurom a kesz hallgatot

            //A hallgatot darabolhattam volna getline-nal is, ',' delimiter karakterrel, de mivel tudtam, hogy hany karakteres, erre nem volt szukseg
        }
    }

    ifs.close();
    return true;
}

void csoportokatKiir(const vector<vector<Hallgato> > &csoportok)
{
    for(size_t i=0;i<csoportok.size();++i)
    {
		cout<<i+1<<". csoport: ";
        for(size_t j=0;j<csoportok[i].size();++j)
        {
            cout<<csoportok[i][j].neptun<<","<<csoportok[i][j].jegy<<" ";
        }
        cout<<endl;
    }
}

void elsoFeladat(const vector<vector<Hallgato> > &csoportok)
{
    if(voltBukoCsoport(csoportok))
        cout<<"Volt olyan csoport, amelyikben mindenki megbukott, pedig nagy letszamu volt."<<endl;
    else
        cout<<"Mindegyik nagy csoportban volt legalabb egy valaki, aki nem bukott meg - vagy nem is volt csoport"<<endl;
}

//Linearis kereses
//[m..n] ~ a teljes csoportok tomb indextartomanya (minden csoport)
//l ~ van
//beta(i) ~ legalabb ket tagu es mindenki megbukott
bool voltBukoCsoport(const vector<vector<Hallgato> > &csoportok)
{
    bool van = false;
    for(size_t i=0;!van && i<csoportok.size();++i)
        van = csoportok[i].size() >= 2 && mindenkiBukott(csoportok[i]);
    return van;
}

//Optimista linearis kereses
//[m..n] ~ a teljes csoport tomb indextartomanya (minden hallgato)
//l ~ mindenki
//beta(i) ~ az aktualis hallgato megbukott
bool mindenkiBukott(const vector<Hallgato> &csoport)
{
    bool mindenki = true;
    for(size_t i=0;mindenki && i<csoport.size();++i)
        mindenki = csoport[i].jegy < 2;
    return mindenki;
}

void masodikFeladat(const vector<vector<Hallgato> > &csoportok, const vector<string> &tanarok)
{
    if(csoportok.empty())   //Elofeltetel - hiszen maximumkivalasztas a tetel
        cout<<"Nincs legjobb hallgato, mert nincs hallgato"<<endl;
    else
        cout<<legjobbCsoportTanara(csoportok, tanarok)<<endl;
}

//Osszetett fuggveny - eleje: maximumkivalasztas; hivaskor ellenorzom, hogy nem ures-e!
//max ~ maxjegy (segedvaltozokent)
//ind ~ ind (a teljes feladat szamara csak segedvaltozo)
//[m..n] ~ minden csoport, ezert a csoportok tomb indextartomanya
//f(i) ~ az i. csoport legjobb elofordulo jegye
//H ~ int, mert a jegy tipusa ez
string legjobbCsoportTanara(const vector<vector<Hallgato> > &csoportok, const vector<string> &tanarok)
{
    int maxjegy = legjobbJegy(csoportok[0]);
    size_t ind = 0;
    for(size_t i=1;i<csoportok.size();++i)
    {
        int aktjegy = legjobbJegy(csoportok[i]);    //FHV
        if(maxjegy < aktjegy)
        {
            maxjegy = aktjegy;
            ind = i;
        }
    }

    return tanarok[ind];    //OF masodik fele
}

//Maximumkivalasztas - hivaskor nem ellenorzom, hogy ures-e, mert tudjuk, hogy minden csoportban van legalabb egy tag (beolvasas feltetele volt)
//max ~ maxjegy
//ind elhagyva
//[m..n] ~ minden hallgato, ezert a csoport tomb indextartomanya
//f(i) ~ az i. hallgato jegye
//H ~ int, mert a jegy tipusa ez
int legjobbJegy(const vector<Hallgato> &csoport)
{
    int maxjegy = csoport[0].jegy;
    for(size_t i=1;i<csoport.size();++i)
        if(maxjegy < csoport[i].jegy)
            maxjegy = csoport[i].jegy;
    return maxjegy;
}
