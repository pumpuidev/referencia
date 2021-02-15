#ifndef ENOR_MONDATHOSSZ_H
#define ENOR_MONDATHOSSZ_H

#include<fstream>
#include"kozos.h"

class Enor_mondathossz
{
	public:
		Enor_mondathossz(std::string fnev);
		~Enor_mondathossz();
		void First();
		void Next();
		bool End();
		int Current();
	private:
		std::ifstream x;
		Status sx;
		int dx;
		char e; //segedvaltozo, a spec. jelek megtalalasahoz (elore olvasas)
};

#endif // ENOR_MONDATHOSSZ_H
