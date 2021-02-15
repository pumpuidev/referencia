#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<vector>

enum Status { norm, abnorm };

struct Varos
{
	std::string nev;
	int lakok;

	friend std::istream& operator>>(std::istream& is, Varos& d);
	friend std::ostream& operator<<(std::ostream& os, const Varos& d);
};

struct Data
{
	std::string orszag;
	std::vector<Varos> varosok;

	friend std::istream& operator>>(std::istream& is, Data& d);
	friend std::ostream& operator<<(std::ostream& os, const Data& d);
};

class Enor
{
public:
	Enor(std::string fnev);
	~Enor();
	void First();
	void Next();
	Data Current() const;
	bool End() const;

private:
	std::ifstream x;
	Status sx;
	Data dx;
};

#endif // ENOR_H_INCLUDED
