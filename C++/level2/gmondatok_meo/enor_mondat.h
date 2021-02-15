#ifndef ENOR_MONDAT_H
#define ENOR_MONDAT_H

#include<fstream>
#include"kozos.h" //ha tobb helyen is kell a Status pl, akkor azt ki kell szedni kulon fajlba,
//mert ha nem, akkor tobbszori definicioja lenne.

class Enor_mondat
{
	public:
		Enor_mondat(std::string fnev);
		~Enor_mondat();
		void First();
		void Next();
		bool End();
		std::string Current();
	private:
		std::ifstream x;
		Status sx;
		std::string dx;
};

#endif // ENOR_MONDAT_H
