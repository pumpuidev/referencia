#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

enum Status { abnorm, norm };

struct Adat
{
	std::string nev;
	int ossz;
	std::string lastdatum;	//uresen marad, ha nem fizette ki
	int reszletek;			//ennyi reszletben fizetett be (uj, az otosert kell)
};

class Enor
{
	public:
		Enor(std::string fnev);
		~Enor();
		void First();
		void Next();
		Adat Current() const { return dt; }
		bool End() const { return st == abnorm; }
	private:
		std::ifstream x;
		Adat dt;
		Status st;
		bool datum(std::string s);
};

#endif // ENOR_H
