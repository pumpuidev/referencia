#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Adat
{
	std::string azon;
	int osszbefiz;
	bool befizette;	//befizette-e a kkoltseg 12-szereset
	bool jolfizetett;	//legalabb egyszer annyit fizetett amennyit kellett
};

class Enor
{
	public:
		Enor(std::string fnev);
		~Enor();
		void First();
		void Next();
		Adat Current() const { return adat; }
		bool End() const { return vege; }
	private:
		std::ifstream x;
		Adat adat;
		bool vege;
		bool datum(std::string s);
};

#endif // ENOR_H
