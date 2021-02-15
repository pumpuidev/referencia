#include <iostream>
#include <vector>
#include <stdio.h>
#include <cctype>

using namespace std;

enum Sex { Male, Female };  //felsorolasi vagy felsorolt (nem felsorolo!) tipus
                            //enumerable, enumerated, (nem enumerator)
struct Animal
{
    string species;
    int age;
    Sex sex;

    //konstruktor
    Animal(string species, int age, string sex)
    {
        this->species = species;    // a this jelentese, az eppen konstrualas alatt allo allat
        this->age = age;            // azert kellett, mert azonosak a parameterek es az adattagok nevei
        this->sex = tolower(sex[0]) == 'm' ? Male : Female; //mert Sex tipusut nem tudok konzolrol beolvasni, csak stringet
    }
};

vector<Animal> readAnimals();
void printAnimals(const vector<Animal> &animals);
bool isValidSex(string sex);

int main()
{
    vector<Animal> animals = readAnimals();

    //a feladat
    unsigned c = 0; //szamlalas
    int s = 0;  //osszegzes
    for(size_t i = 0;i<animals.size();++i)  //egyszerre, mert kozos az intervallum
    {
        if(animals[i].species == "lion") //ez egyszerre egy beta (szamlalas) es egy EDF feltetele (osszegzes)
        {
            ++c;
            s += animals[i].age;
        }
    }

    if(c == 0) //ez az "l"
        cerr<<"No lion. No party."<<endl;
    else
        cout<<s/(double)c<<endl; //hogy nehogy egeszosztas legyen

    return 0;
}

vector<Animal> readAnimals()
{
    vector<Animal> animals;

    //ez egy olyan beolvasas, hogy ha sikertelen volt, akkor megkerdezi, akarod-e ujra beolvasni
    bool retry = true;
    do
    {
        string species;
        int age;
        string sex;
        cin>>species>>age>>sex; //itt primitiv segedvaltozokat hozok letre, nem a rekordom tipusat, mert van konstruktor

        bool fail = cin.fail() || age < 0 || !isValidSex(sex);
        if(fail)    //ha hiba van, eldontheti hogy akarja-e folytatni
        {
            cerr<<"Bad input. Continue? (y/n)"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            string answer;
            cin>>answer;
            retry = answer.size() == 1 && tolower(answer[0]) == 'y';
        }
        else
        {
            animals.push_back(Animal(species, age, sex));
        }

        printAnimals(animals);
    }
    while(retry);

    return animals;
}

bool isValidSex(string sex)
{
    if(sex.size() == 1) //kell az elofeltetel, mert a nulladik elemet direkte cimzem utana (csak emiatt eleg lenne hogy nem ures)
        return tolower(sex[0]) == 'f' || tolower(sex[0]) == 'm';
    return false;

    //avagy:
    //return sex == "F" || sex == "M" || sex == "f" || sex == "m";
}

void printAnimals(const vector<Animal> &animals)
{
    for(size_t i=0; i<animals.size();++i)
    {
        Animal a = animals[i];
        cout<<"> "<<a.species<<" "<<a.age<<" ";
        if(a.sex == Male)
            cout<<"male";
        else if(a.sex == Female)
            cout<<"female";
        cout<<endl;
    }
}
