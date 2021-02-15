#include "enor_mondat.h"

using namespace std;

Enor_mondat::Enor_mondat(string fnev)
{
	x.open(fnev.c_str());
}

Enor_mondat::~Enor_mondat()
{
	x.close();
}

void Enor_mondat::First()
{
	sx = norm;
	Next();
}

void Enor_mondat::Next()
{
	getline(x,dx,'.');	//azert ez nem teljesen tokeletes, mert mindenfele szokozoket meg ujsorokat meghagy,
						//raadasul, ha van a fajl vegen ujsor, azt is beolvassa ures mondatkent, hiszen
	if(x.fail())		//neki most csak a '.' szamit, az ujsor jel nem. ha ezt javitani akarnank, ebben a muveletben lenne keresnivalonk
		sx = abnorm;	//pl. atirni a beolvasast karakterenkenti get ciklusra.
}

bool Enor_mondat::End()
{
	return sx == abnorm;
}

string Enor_mondat::Current()
{
	return dx;
}
