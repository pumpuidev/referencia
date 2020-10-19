#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
int n=2;

struct allomas
{
    string nev;
    int leszallo;
    int felszallo;
};

double E (allomas a[]); //Deklaracio
string P (allomas a[]);
int Y (allomas a[]);
bool EE (allomas b[]);
void szam(int &a);

int main()
{
    string line;
   ifstream myfile ("teszt.txt");
   string eldontes;
   cout<<"Billentyuzetrol akarsz beolvasni?(y/n)"<<endl;
   cin>>eldontes;

   if(eldontes=="y")  // Billrol
   {
        cout<<"Ird be hogy hany allomas volt";
        szam(n);
        while(n<2)
        {   cout<<"Legalabb ketto allomas volt,ird be ujra!: ";
            szam(n);
        }
   }
   else //Fajl
   {
       getline(myfile,line);
       n=atoi(line.c_str());
   }
   allomas megallo[n];
   if(eldontes=="y")
   {


        megallo[0].nev="Budapest";
        megallo[0].leszallo=0;
        cout<<"Ird be a budapesti felszallok szamat: ";
        szam(megallo[0].felszallo);
        for(int i=1;i<(n-1);++i)
        {
            cout<<"Ird be az "<<i+1<<".-edik allomas nevet: ";
            cin>>megallo[i].nev;
                        cout<<"Ird be az "<<i+1<<".-edik allomasnal a felszallok szamat: ";
            szam(megallo[i].felszallo);
            cout<<"Ird be az "<<i+1<<".-edik allomasnal a leszallok szamat: ";
            szam(megallo[i].leszallo);
        }
        megallo[n-1].nev="Szekesfehervar";
        megallo[n-1].felszallo=0;
        cout<<"Ird be a szekesfehervari leszallok szamat: ";
        szam(megallo[n-1].leszallo);


   }
    else
    {
        for (int i=0;i<n;++i)
        {
            getline(myfile,line);
            stringstream ss(line);
            string buf;
            ss>>buf;
            megallo[i].nev=buf;
            ss>>buf;
            megallo[i].felszallo=atoi(buf.c_str());
            ss>>buf;
            megallo[i].leszallo=atoi(buf.c_str());
        }
        myfile.close();
    }

    for(int i=0;i<n;++i)
    {
        cout<<megallo[i].nev<<" "<<megallo[i].felszallo<<" "<<megallo[i].leszallo<<endl;
    }





    double atlagosleszallok = E(megallo);

cout << "E feladat, az atlagos leszallok szama: "<<atlagosleszallok<<endl;

string legtobbleszallo = P(megallo);

cout<<"P feladat, a legtobb leszallo a(z)"<<legtobbleszallo<<" allomason volt."<<endl;

int db = Y(megallo);
cout<<"Y feladat, az allomasok szama,ahol mindenki leszallt: "<<db<<endl;

bool l= EE(megallo);
if(l==true)
{
    cout<<"EE feladat,volt olyan megallo,ahol tobb ember szallt le,mint amennyien a vonaton voltak."<<endl;
}
else
{
    cout<<"EE feladat,nem volt olyan megallo,ahol tobb ember szallt le,mint amennyien a vonaton voltak."<<endl;
}

    return 0;
}

double E (allomas a[])
{
    int db=0;
    double atlag=0;
    for(int i=0;i<n;++i)
    {
        ++db;
        atlag=atlag+a[i].leszallo;
    }
    atlag=atlag/db;
    return atlag;
}

string P (allomas a[])
{
    string nev="Budapest";
    int maximum=0;
    for(int i=1;i<n;++i)
    {
        if(a[i].leszallo>maximum)
        {
            maximum=a[i].leszallo;
            nev=a[i].nev;
        }
    }
    return nev;
}

int Y (allomas a[])
{
    int db=0;
    int utas=a[0].felszallo;
    for(int i=1;i<n;++i)
    {
        utas=utas-a[i].leszallo;
        if(utas==0)
        {
            ++db;
        }
        utas=utas+a[i].felszallo;
    }
    return db;
}

bool EE (allomas b[])
{
    int utas=b[0].felszallo;
    bool l=false;
    for(int i=1;i<n;++i)
    {
        utas=utas-b[i].leszallo;
        if(utas<0)
        {
            l=true;
        }
        utas=utas+b[i].felszallo;
    }
    return l;
}

void szam(int &a)
{

	cin >> a;
	while(cin.fail() || a<0 )
	{
		cout << "Egy pozitiv szamot kell beirni!"<< endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> a;
	}
}
