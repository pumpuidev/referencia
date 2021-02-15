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
};

struct Data
{
	std::string orszag;
	std::vector<Varos> varosok;
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
	Status st;
	Data dt;
};

#endif // ENOR_H_INCLUDED
