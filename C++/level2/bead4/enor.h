#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<vector>

struct Orszag
{
	std::string nev;	//ez az orszag neve
	int vdb;			//ennyi varosban van jelen ebben az orszagban
	int ossz;			//ennyi az orszag varosainak ossz lakossaga
	//megj.: a varosok neveire nem is vagyunk kivancsiak!
};

class Enor
{
public:
	Enor(std::string fnev);
	~Enor();
	void First();
	void Next();
	Orszag Current() const;
	bool End() const;

private:
	std::ifstream x;
	bool vege;
	Orszag o;
};

#endif // ENOR_H_INCLUDED
