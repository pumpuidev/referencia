#ifndef ENOR_TOMB_H
#define ENOR_TOMB_H

#include<cstdlib>
#include<vector>

class Enor_tomb
{
	public:
		Enor_tomb(std::vector<int> v);
		void First();
		void Next();
		bool End() const;
		int Current() const;    //ez nem az az int mint a másik felsorolónál. ez azért int, mert int van a tombben

	private:
		std::vector<int> v; //nincs n és m, mert a tömbbol ki lehet talalni... tablas gyakon sem volt sose a konkret vektoros feladatokban
		size_t i;			//itt akár lehtne egy intervallum felsorolo is alatta
};

#endif // ENOR_TOMB_H
