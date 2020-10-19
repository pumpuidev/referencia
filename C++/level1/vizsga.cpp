#include <iostream>
/*
A város egy forgalmas pontján N napon keresztül mindennap mérték a légszennyezõdés mértékét reggel és este. Írjon programot amely megoldja az alábbi feladatokat:
A.) Melyik nap nõtt a legnagyobb mértékben estére a szennyezõdés mértéke(ha több ilyen nap van, akkor az elsõt kell megadni, ha nincs ilyen akkor a 0-t)
B.) azon napok száma, amikor a reggeli érték nagyobb volt mint az elõzõ naou reggeli érték és az esti érték is nagyobb volt, mint az elõzõ napi esti érték
C.) azon napok száma, és a napok növekvõ sorrendben (egy-egy szóközzel elválasztva), amikor az esti érték nagyobb volt, mint az esti értékek átlaga.
D.) a leghosszabb összefüggõ idõintervallum elsõ és utolsó napja, amikor az esti érték meghaladta a reggeli értékét (ha több ilyen megoldás is van, akkor a legkisebb elsõ napját, ha nincs megoldás akkor az egyetlen 0 számot kell kiírni)
bemenet:*/
using namespace std;

int main()
{
int n;
cin >> n;
int reggel[n];
int este[n];
for (int i=0;i<n;i++)
{
    cin >> reggel[i];
    cin >> este[i];
}

// elso
int max = 0;
for (int i = 1; i < n; i++)
   {
    if((este[i]-reggel[i]) > (reggel[max]-este[max]))
        {
            max = i;
        }
   }
cout << max << endl;
// masodik
int db=0;
for (int i = 0;i < n ; i++)
{
if(reggel[i+1]>reggel[i] && este[i+1]>este[i])
db++;
}
cout << db << endl;
// harmadik
int s=0;
for (int i=0 ; i<n;i++)
    {
        s=s+este[i];
    }

float atlag;
atlag = s/n;
int atlagnagyobb = 0;
for (int i = 0;i < n ; i++)
    {
        if(este[i]> atlag)
        atlagnagyobb++;
    }
cout << atlagnagyobb <<" ";
for (int i = 0;i < n ; i++)
    {
        if(este[i]> atlag)
        {
            cout <<i+1<<" ";
        }
    }
//negyedik

/*annyi az egész, h. létrehozol egy logikai változót,
ami 2 állapotot színbolizál
ha 1-es, akkor épp egy intervallumban vagy
ha 0, akkor nem vagy intervallumban
ha 0-ból lépsz 1-be, akkor adod meg a napsz-t,
meg nullázod a hosszt
ha 1-bõl lépsz 1-be, akkor csak növeled a hosszt
ha 1-bõl 0-ba, akkor vizsgálod, hogy ami intervallumból kiléptél,
az nagyobb-e, mint az eddigi max
ha meg 0-ból 0-ba, akkor nem csinálsz semmit
csak lépsz tovább */
int napsz=0;
int hossz=0;
int maxnapsz=0;
int maxhossz=0;
bool allapot=0;

for (int i=0;i<n;i++)
{
	if (este[i]>reggel[i])
	{
		if(allapot==0)
		{
			allapot=1;
			napsz=i;
			hossz=1;
		}
		else
		{
			hossz++;
		}

	}
	else
	{
		if(allapot==1)
		{
			allapot=0;
			if(hossz>maxhossz)
			{
				maxhossz=hossz;
				maxnapsz=napsz;
			}
		}
	}
}

cout <<maxnapsz+1 <<" "<<maxnapsz+maxhossz;
}
/*
max min kiválasztás:
int min = 0;int max = 0;for (int i = 1; i < n; i++){if (szamok[i] < szamok[min]){min = i;}if (szamok[i] > szamok[max]){max = i;}}
megszámlálás:
int db = 0;for (int i = 0; i < n; i++){if (szamok[i] > 80){db++;}}
