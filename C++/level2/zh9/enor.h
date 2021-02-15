#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

enum Status { abnorm, norm };

struct Par
{
	std::string datum;
	int penz;
};

struct Diak
{
	std::string nev;
	std::vector<Par> befiz;
};

class Enor
{
	public:
		Enor(std::string fnev);
		~Enor();
		void First();
		void Next();
		Diak Current() const;
		bool End() const;
	private:
		std::ifstream x;
		Diak dx;
		Status sx;
};

#endif // ENOR_H
