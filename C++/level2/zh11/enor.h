#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Par
{
	std::string datum;
	int penz;
};

struct Lakas
{
	std::string azon;
	int kkoltseg;
	std::vector<Par> befiz;
};

class Enor
{
	public:
		Enor(std::string fnev);
		~Enor();
		void First();
		void Next();
		Lakas Current() const { return dx; }
		bool End() const { return vege; }
	private:
		std::ifstream x;
		Lakas dx;
		bool vege;
};

#endif // ENOR_H
