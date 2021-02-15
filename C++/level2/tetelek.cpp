/*
	OSSZEGZES
*/

//absztrakt osszegzes tetel
//s-sel ter vissza, ami H tipusu, parametere az intervallum hatarai.
//feltelezzuk, hogy H-nak van nulleleme es osszeadas muvelete.
//feltetelezzuk, hogy [m..n]-en van egy f fuggveny ertelmezve
H osszegzes(int m, int n)
{
	H s = NULLELEM;
	for(int i=m;i<=n;++i)
		s = s OSSZEADAS f(i);

	return s;
}

//osszegzes tetel, ha H~Z (azaz int)
//nyugodtan lehet a rovidebb += format hasznalni
int osszegzes(int m, int n)
{
	int s = 0;
	for(int i=m;i<=n;++i)
		s += f(i);

	return s;
}

//osszegzes ha vektoron kell elemenkent "valamit" (f-et) csinalni
int osszegzes(vector<int> v)
{
	int s = 0;
	for(size_t i=0;i<v.size();++i)	//a meret es index legyen mindig size_t, mert maga a v.size() azzal ter vissza
		s += f(v[i]);

	return s;
}

//konkret pelda1: vektor elemeinek a rakovetkezoinek az osszeszorzasa
int osszegzes(vector<int> v)
{
	int s = 1;
	for(size_t i=0;i<v.size();++i)
		s *= (v[i] + 1);

	return s;
}

//konkret pelda2: szavakat tartalmazo vektor szavainak osszefuzese uj sorokba
string osszegzes(vector<string> v)
{
	string s = "";
	for(size_t i=0;i<v.size();++i)
		s += (v[i] + "\n");

	return s;
}

/*
	SZAMLALAS
*/

//absztrakt szamlalas tetel
//c-vel ter vissza, ami 0-rol indul es csak noni tud (tehat term. szam)
//feltelezzuk hogy van [m..n] intervallum
//es egy azon ertelmezett beta logikai feltetel
int szamlalas(int m, int n)
{
	int c = 0;
	for(int i=m;i<=n;++i)
		if(beta(i))
			++c;

	return c;
}

//konkret pelda1: [a..b] intervallumon hany negyzetszam van?
int szamlalas(int a, int b)
{
	int c = 0;
	for(int i=a;i<=b;++i)
	{
		int gyok = sqrt(i);	//kell a math.h hozza! - mivel int, alsoegeszreszet kapjuk meg
		if(gyok*gyok == i)	//de ha ezt negyzetre emelve visszakapom i-t,
			++c;			//akkor valoban egesz szam volt a gyoke, azaz negyzetszam
	}

	return c;
}

//konkret pelda2: szavak tombjeben hany a-val kezdodo van?
int szamlalas(vector<string> v)
{
	int c = 0;
	for(size_t i=0;i<v.size();++i)
		if(v[i].length()>0 && v[i][0] == 'a')	//lusta kiertekeles miatt fontos a ket feltetel sorrendje.
			++c;								//azert '.' jelek kozott van az a, mert az egy karakter. (string=karakterek sorozata)

	return c;
}

/*
	MAXKIV
*/

//absztrakt maxkiv tetel
//adott egy H tipusunk amin van "nagyobb" relacio ertelmezve.
//adott [m..n] intervallum, ami nem ures,
//valamint [m..n]-en ertelmezett H-ra kepzo f fuggveny...
struct Par
{
	int ind;
	H max;
};

Par maxkiv(int m, int n)
{
	Par p;
	p.max = f(m);
	p.ind = m;
	for(int i=m+1;i<=n;++i)
	{
		if(f(i) NAGYOBB p.max)
		{
			p.max = f(i);
			p.ind = i;
		}
	}

	return p;
}

//ind elhagyasaval
H maxkiv(int m, int n)
{
	H max = f(m);
	for(int i=m+1;i<=n;++i)
		if(f(i) NAGYOBB max)
			max = f(i);

	return max;
}

//max elhagyasaval
int maxkiv(int m, int n)
{
	int ind = m;
	for(int i=m+1;i<=n;++i)
		if(f(i) NAGYOBB f(ind))	//ez egy kis egyszerusites
			ind = i;

	return ind;
}

//maxszal ter vissza, indet mellekhataskent modositja
H maxkiv(int m, int n, int& ind)
{
	H max = f(m);
	ind = m;
	for(int i=m+1;i<=n;++i)
	{
		if(f(i) NAGYOBB max)
		{
			max = f(i);
			ind = i;
		}
	}

	return max;
}

//inddel ter vissza, maxot mellekhataskent modositja
int maxkiv(int m, int n, H& max)
{
	max = f(m);
	int ind = m;
	for(int i=m+1;i<=n;++i)
	{
		if(f(i) NAGYOBB max)
		{
			max = f(i);
			ind = i;
		}
	}

	return ind;
}

//eljaraskent - semmivel nem ter vissza, mindket kimenonek szant valtozo mellekhataskent kap erteket
void maxkiv(int m, int n, H& max, int& ind)
{
	max = f(m);
	ind = m;
	for(int i=m+1;i<=n;++i)
	{
		if(f(i) NAGYOBB max)
		{
			max = f(i);
			ind = i;
		}
	}
}

//konkret pelda1: a legkisebb szam indexe egy tombben
size_t maxkiv(vector<int> v)
{
	size_t ind = 0;
	for(size_t i=1;i<v.size();++i)
		if(v[i] < v[ind])
			ind = i;

	return ind;
}

//konkret pelda2: a legnagyobb kiraly
string maxkiv()
{
	return "Pisont Istvan"; //:)
}

//konkret pelda2: na, komolyan
struct Kiraly
{
	int magassag;
	string nev;
};

Kiraly maxkiv(vector<Kiraly> v)
{
	Kiraly max = v[0];
	for(size_t i=1;i<v.size();++i)
		if(v[i].magassag > max.magassag)	//ha a Kiralyon igy van definialva a >
			max = v[i];

	return max;
}

/*
	Felteteles maximumkereses
*/

//absztrakt feltmaxker.
//adott az [m..n] intervallum, a rendezheto H halmaz,
//az intervallumrol H-ra kepzo f es L-re kepzo beta...

struct Harmas
{
	int ind;
	H max;
	bool l;
};

Harmas feltmaxker(int m, int n)
{
	Harmas h;
	h.l = false;
	for(int i=m;i<=n;++i)
	{
		if(beta(i))		//a harmas elagazas nembeta aga ennek az else aga (amit elhagyhattunk, mert skip)
		{
			if(h.l)		//ez a beta es l ag
			{
				if(f(i) NAGYOBB h.max)
				{
					h.max = f(i);
					h.ind = i;
				}
			}
			else		//ez a beta es nem l ag
			{
				h.l = true;
				h.max = f(i);
				h.ind = i;
			}
		}
	}

	return h;
}

//sok fele egyeb modon lehet megoldani a kimeno valtozokat, nekem ez
//a legszimpatikusabb. azzal terek vissza, hogy volt-e talalat, es ha igen,
//akkor a paramterekbe kerul a megoldas
bool feltmaxker(int m, int n, int& ind, H& max)
{
	bool l = false;
	for(int i=m;i<=n;++i)
	{
		if(beta(i))
		{
			if(l)
			{
				if(f(i) NAGYOBB max)
				{
					max = f(i);
					ind = i;
				}
			}
			else
			{
				l = true;
				max = f(i);
				ind = i;
			}
		}
	}

	return l;
}

//konkret pelda1: mi az erteke es indexe a tomb legnagyobb paros szamanak?
bool feltmaxker(vector<int> v, size_t& ind, int& max)
{
	bool l = false;
	for(size_t i=0;i<v.size();++i)
	{
		if(v[i] % 2 == 0)
		{
			if(l)
			{
				if(v[i] > max)
				{
					max = v[i];
					ind = i;
				}
			}
			else
			{
				l = true;
				max = v[i];
				ind = i;
			}
		}
	}

	return l;
}

//konkret pelda2: mi a neve a legalacsonyabb keksapkas torpenek?
//(osszetett fuggveny)

struct Torpe
{
	int magassag;
	string sapiszin;
	string nev;
};

bool feltmaxker(vector<Torpe> v, string& nev)
{
	size_t ind;		//segedvaltozo
	bool l = false;
	for(size_t i=0;i<v.size();++i)
	{
		if(v[i].sapiszin == "kek")
		{
			if(l)
			{
				if(v[i].magassag < v[ind].magassag)
					ind = i;
			}
			else
			{
				l = true;
				ind = i;
			}
		}
	}

	if(l)
		nev = v[ind].nev;	//itt nyilvanul meg az osszetett fv-seg

	return l;
}

/*
	KIVALASZTAS
*/

//absztrakt kivalasztas tetel
//van egy m egesz szam, es ra, valamint a nala nagyobbakra ertelmes
//megkerdezni, hogy igaz-e a beta. legalabb egy ponton igaz is lesz, azt keressuk

int kivalasztas(int m)
{
	int i = m;
	while(!beta(i))
		++i;

	return i;
}

//konkret pelda1: melyik az elso primszam "k"-tol? (ha kifejezetten k utan, akkor k+1-tol kezdunk...)
int kivalasztas(int k)
{
	int i = k;
	while(!prim(i))
		++i;

	return i;
}

//konkret pelda2: keressuk meg a 0-t egy szamokat tartalmazo tombben (ha feltehetjuk, hogy benne van)
//indexet adjunk vissza!
size_t kivalasztas(vector<int> v)
{
	size_t i = 0;
	while(v[i] != 0)
		++i;

	return i;
}

/*
	LINKER
*/

//absztrakt linearis kereses.
//van megint az [m..n] intervallum
//es az azon ertelmezett beta
struct Par
{
	bool l;
	int ind;
};

Par linker(int m, int n)
{
	Par p;
	p.l = false;
	int i = m;
	while(!p.l && i<=n)
	{
		p.l = beta(i);
		p.ind = i;
		++i;
	}

	return p;
}

//always look on the bright side of life
//avagy ugyanez optimistaul!
struct Par
{
	bool l;
	int ind;
};

Par linker(int m, int n)
{
	Par p;
	p.l = true;
	int i = m;
	while(p.l && i<=n)
	{
		p.l = beta(i);
		p.ind = i;
		++i;
	}

	return p;
}

//pesszimista linker ugy, hogy igazzal ter vissza, ha van talalat
//es ind-be mellekhataskent adja meg azt (ha van)
bool linker(int m, int n, int& ind)
{
	bool l = false;
	int i = m;
	while(!l && i<=n)
	{
		l = beta(i);
		ind = i;
		++i;
	}

	return l;
}

//olyan linker, ahol annyi csak a kerdes, van-e.
//indet jol elhagyhattuk
bool linker(int m, int n)
{
	bool l = false;
	int i = m;
	while(!l && i<=n)
	{
		l = beta(i);
		++i;
	}

	return l;
}

//konkret pelda1: van-e egy intervallumon p-vel oszthato szam, ha igen, melyik az?
bool linker(int a, int b, int p, int& ind)
{
	bool l = false;

	for(int i=a; !l && i<=b;++i)	//irhatjuk nyugodtan foros alakban is!
	{
		l = i % p == 0;
		ind = i;
	}

	/*int i = a;
	while(!l && i<=b)
	{
		l = i % p == 0;
		ind = i;
		++i;
	}*/

	return l;
}

//konkret pelda2: egy tomb minden eleme pozitiv vajon?
bool linker(vector<int> v)
{
	bool l = true;

	for(size_t i=0; l && i<v.size();++i)
		l = v[i] > 0;

	return l;
}
