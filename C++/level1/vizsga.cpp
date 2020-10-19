#include <iostream>
/*
A v�ros egy forgalmas pontj�n N napon kereszt�l mindennap m�rt�k a l�gszennyez�d�s m�rt�k�t reggel �s este. �rjon programot amely megoldja az al�bbi feladatokat:
A.) Melyik nap n�tt a legnagyobb m�rt�kben est�re a szennyez�d�s m�rt�ke(ha t�bb ilyen nap van, akkor az els�t kell megadni, ha nincs ilyen akkor a 0-t)
B.) azon napok sz�ma, amikor a reggeli �rt�k nagyobb volt mint az el�z� naou reggeli �rt�k �s az esti �rt�k is nagyobb volt, mint az el�z� napi esti �rt�k
C.) azon napok sz�ma, �s a napok n�vekv� sorrendben (egy-egy sz�k�zzel elv�lasztva), amikor az esti �rt�k nagyobb volt, mint az esti �rt�kek �tlaga.
D.) a leghosszabb �sszef�gg� id�intervallum els� �s utols� napja, amikor az esti �rt�k meghaladta a reggeli �rt�k�t (ha t�bb ilyen megold�s is van, akkor a legkisebb els� napj�t, ha nincs megold�s akkor az egyetlen 0 sz�mot kell ki�rni)
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

/*annyi az eg�sz, h. l�trehozol egy logikai v�ltoz�t,
ami 2 �llapotot sz�nboliz�l
ha 1-es, akkor �pp egy intervallumban vagy
ha 0, akkor nem vagy intervallumban
ha 0-b�l l�psz 1-be, akkor adod meg a napsz-t,
meg null�zod a hosszt
ha 1-b�l l�psz 1-be, akkor csak n�veled a hosszt
ha 1-b�l 0-ba, akkor vizsg�lod, hogy ami intervallumb�l kil�pt�l,
az nagyobb-e, mint az eddigi max
ha meg 0-b�l 0-ba, akkor nem csin�lsz semmit
csak l�psz tov�bb */
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
max min kiv�laszt�s:
int min = 0;int max = 0;for (int i = 1; i < n; i++){if (szamok[i] < szamok[min]){min = i;}if (szamok[i] > szamok[max]){max = i;}}
megsz�ml�l�s:
int db = 0;for (int i = 0; i < n; i++){if (szamok[i] > 80){db++;}}
