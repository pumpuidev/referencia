#include <iostream>
#include <vector>

using namespace std;

vector<int> readVector(); //elorevetett deklaracio (forward declaration)
void printVector(const vector<int> &v);
int scalarProduct(const vector<int> &v1,const vector<int> &v2);

int main()
{
    cout<<"Az elso vektor beolvasasa:"<<endl;
    vector<int> v1 = readVector();
    cout<<"A masodik vektor beolvasasa:"<<endl;
    vector<int> v2 = readVector();

    //ellenorzeskepp
    cout<<"Az elso vektor:"<<endl;
    printVector(v1);
    cout<<"A masodik vektor:"<<endl;
    printVector(v2);

    if(v1.size() == v2.size())  //ez a feltetel a tetel elofeltetele, de nem igazan a beolvasas helyessegenek feltetele, ezert itt "kulon" vizsgalom
    {
        cout<<"A skalaris szorzat:"<<endl;
        cout<<scalarProduct(v1,v2);
    }
    else
    {
        cout<<"A ket vektor eltero meretu, nincs skalaris szorzat"<<endl;
    }

    return 0;
}

vector<int> readVector()
{
    vector<int> v;  //ekkor meg ures

    int e;
    while(cin>>e)   //amig sikerul (tipushelyesen) olvasni; ide mas feltetel (is) kerulhetne, akar e-re vonatkozoan is
    {
        v.push_back(e);
    }

    cin.clear();    //mivel failig olvasunk, ezert a vegere "elromlik" majd a cin (es ekkor nem lehet olvasni rola)
    cin.ignore(1000,'\n');  //ki kell javitani hiszen ezt a fuggvenyt majd masodszor is meghivjuk

    return v;
}

void printVector(const vector<int> &v)
{
    for(size_t i = 0; i<v.size(); ++i)
        cout<<v[i]<<" ";
    cout<<endl;
}

int scalarProduct(const vector<int> &v1,const vector<int> &v2)
{
    //erdemesebb intkent visszaterni, es a foprogramban kiirni, mint itt kiirni
    //okok:
    //1) igy kifejezobb
    //2) ez a fuggveny igy egy igazi fv., csak szamol valamit, nem csinal mellette mast (nincs mellekhatasa)
    //3) konnyebb igy unit testet irni erre
    //4) elvalik a kiszamitas es a kiiras, ami hasznos, gondoljunk bele ha pl. allithato lenne, hogy a program angolul vagy magyarul legyen - eleg lenne csak a foprogramot atirni, nem kell ezt a nyelvfuggetlen szamitast is

    //osszegzes tetel
    int s = 0;  //mivel a vectorokban is intek vannak, es ezek szorzatait osszegezzuk, ez is int lesz
    for(size_t i = 0; i<v1.size(); ++i) //ef: azonos a ket meret
        s += v1[i] * v2[i];
    return s;
}
