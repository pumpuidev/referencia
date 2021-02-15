#include <iostream>
#include <vector>

using namespace std;

struct Incident //egy incidens tipusa, ilyenek lesznek a vektorban
{
    string reason;  //adattagok a feladatszoveg alapjan
    int gonzo;
    int duke;
};

vector<Incident> readData();
void printJourney(const vector<Incident> &journey);
string getMostSeriousIncident(const vector<Incident> &journey);

int main()
{
    vector<Incident> journey = readData();
    if(journey.empty())
        cerr<<"Nem tortent semmi varatlan az ut soran (vagy mar elfelejtodott...)"<<endl;
    else
        cout<<"A legsulyosabb problema: "<<getMostSeriousIncident(journey)<<endl;
    return 0;
}

vector<Incident> readData()
{
    vector<Incident> journey;
    bool success;
    do
    {
        Incident incidentToInsert;      //1. hozzunk letre egy valtozot a beillesztendo tipusbol
        cin>>incidentToInsert.reason;   //2. olvassuk be az adattagjait
        cin>>incidentToInsert.duke;
        cin>>incidentToInsert.gonzo;

        success = !cin.fail() &&
                  incidentToInsert.duke >= 0 && //termeszetes szam
                  incidentToInsert.gonzo >=0;
        cin.clear();
        cin.ignore(1000,'\n');

        if(success)     //3. ha sikeres volt, rakjuk be a listaba
            journey.push_back(incidentToInsert);    //az incidentToInsert valtozo megszunik ugyan, de az erteke megorzodik itt
    }
    while(success); //elso hibasig olvasunk
    return journey;
}

void printJourney(const vector<Incident> &journey) //ellenorzo kiiras
{
    for(size_t i=0; i<journey.size();++i)
    {
        Incident e = journey[i];
        cout<<e.reason<<" "<<e.duke<<" "<<e.gonzo<<endl;
    }
}

//maxkiv + osszetett fv. (mert az incidens neve kell, nem az indexe, plane a sulyossaga)
string getMostSeriousIncident(const vector<Incident> &journey)
{
    int max = journey[0].gonzo + journey[0].duke; //f fuggveny az incidens sulyossaga
    size_t ind = 0;
    for(size_t i=1;i<journey.size();++i)
    {
        if(max < journey[i].gonzo + journey[i].duke)
        {
            max = journey[i].gonzo + journey[i].duke;   //a max a tetel (es az egesz fv.) szempontjabol segedvaltozo
            ind = i;    //az ind a tetel szempontjabol nem, de a fv. szempontjabol segedvaltozo (se nem inputja, se nem outputja; lokalis)
        }
    }
    return journey[ind].reason;
}
