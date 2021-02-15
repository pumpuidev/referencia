#include "csoki.h"

using namespace std;

/*
	Megallapitja, hogy a parameterul adott "osztalyzatok" tomb minden elemere igaz-e
	hogy egy ures tomb, vagy az atlaga legalabb 4
	(optimista linearis kereses tetel)
*/
bool optlinker(const vector<vector<int> > &osztalyzatok)
{
	bool l = true;

	for(int i=0;l && i<(int)osztalyzatok.size();++i)
		l = osztalyzatok[i].size() == 0 || (osszeg(osztalyzatok[i]) / (double)osztalyzatok[i].size()) >= 4.0;

	return l;
}

/*
	Kiszamolja a parameterul atadott "korosztaly" vektor elemeinek osszeget
	(osszegzes tetel)
*/
int osszeg(const vector<int> &korosztaly)
{
	int s = 0;

	for(int i=0;i<(int)korosztaly.size();++i)
		s += korosztaly[i];

	return s;
}
